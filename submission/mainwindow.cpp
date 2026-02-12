#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <prac/QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    
    ui->btn_pause->setIcon(QIcon(":/icons/play.png"));     // устанавливаем иконку на кнопку play

    player_ = new prac::QMediaPlayer(this);
    audio_output_= new QAudioOutput(this);

    player_->setAudioOutput(audio_output_);
    player_->setVideoOutput(ui->video_output);

    connect(ui->sld_volume, &QSlider::valueChanged, this, &MainWindow::on_sld_volume_valueChanged);
    connect(ui->sld_pos, &QSlider::valueChanged, this, &MainWindow::on_sld_pos_valueChanged);

    connect(player_, &prac::QMediaPlayer::positionChanged, this, &MainWindow::on_position_changed);
    connect(player_, &prac::QMediaPlayer::mediaStatusChanged, this, &MainWindow::on_media_status_changed);
    connect(player_, &prac::QMediaPlayer::playbackStateChanged, this, &MainWindow::on_playback_state_changed);

    audio_output_->setVolume(1.f);
}

void MainWindow::on_position_changed(qint64 position) {
    
    position_changing_ = true;
    ui->sld_pos->setValue(static_cast<int>(position));
    position_changing_ = false;
}

void MainWindow::on_media_status_changed(QMediaPlayer::MediaStatus status) {
    
    if(status == QMediaPlayer::LoadedMedia || status == QMediaPlayer::BufferedMedia){
    ui->sld_pos->setMaximum(player_->duration());
    }
}

void MainWindow::on_playback_state_changed(QMediaPlayer::PlaybackState new_state) {
    
    if(new_state == QMediaPlayer::PlaybackState::PlayingState){
        ui->btn_pause->setIcon(QIcon(":/icons/pause.png"));
    }
    else{
        ui->btn_pause->setIcon(QIcon(":/icons/play.png"));
    }

}

void MainWindow::on_btn_choose_clicked() {                     // кнопка выбора видеофайла
   
    QString file = prac::QFileDialog::getOpenFileName(this, "Выберите медиафайл");
    player_->setSource(QUrl::fromLocalFile(file));
    player_->play();
}

void MainWindow::on_btn_pause_clicked() {                    // кнопка паузы
    
    switch(player_->playbackState()){
    case QMediaPlayer::PlaybackState::PausedState:
        player_->play();
        break;

    case QMediaPlayer::PlaybackState::StoppedState:
        player_->setPosition(0);
        player_->play();
        break;
    case prac::QMediaPlayer::PlaybackState::PlayingState:
        player_->pause();
        break;
    }
}

void MainWindow::on_sld_volume_valueChanged(int value) {
    
    audio_output_->setVolume(value / 100.f);     // громкость 
}

void MainWindow::on_sld_pos_valueChanged(int value) {   // слайдер измениния громкости видеоплеера
   
    if(position_changing_) {
        return;
    }
    position_changing_ = true;       // флаг изменения позиции
    player_->setPosition(value);
    position_changing_ = false;    //   флаг изменения позиции
}

MainWindow::~MainWindow() {    // деструктор(очищаем память)
    delete ui;
}
