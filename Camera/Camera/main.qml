import QtQuick 2.15
import QtQuick.Window 2.15
import QtMultimedia 5.15
Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")
//////////////////////////////////////////////
//    MediaPlayer {
//            id: player
//            source: "qrc:/video/second.mp4"
//            autoPlay: true
//        }
                                            //второй пример по подключению видео
//        VideoOutput {
//            id: videoOutput
//            source: player
//            anchors.fill: parent
//        }
//////////////////////////////////////////////

/////на компе не работает
        Camera {
            id: camera
            imageProcessing.whiteBalanceMode: CameraImageProcessing.WhiteBalanceFlash
            digitalZoom: zoomSlider.value
            exposure.exposureCompensation: -1.0
            exposure.exposureMode: Camera.ExposurePortrait
            flash.mode: Camera.FlashRedEyeReduction
            imageCapture.onImageCaptured: {
               // addPicture()
            }

//            exposure {
//                exposureCompensation: -1.0
//                exposureMode: Camera.ExposurePortrait
//            }

//            flash.mode: Camera.FlashRedEyeReduction

//            imageCapture {
//                onImageCaptured: {
//                    photoPreview.source = preview  // Show the preview in an Image
//                }
//            }
        }






}
