#include "ckeystonecomm.h"

#include <QCoreApplication>
#include <QThread>


int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	uint16_t	channel	= 2;

	cKeyStoneCOMM	keyStoneCOMM("COM7");
	qDebug() << "Open Radio:         " << keyStoneCOMM.open();
	qDebug() << "Number of Channels: " << keyStoneCOMM.channelCount();
	qDebug() << "Volume:             " << keyStoneCOMM.volume();
	qDebug() << "Start play:         " << keyStoneCOMM.startStream(cKeyStoneCOMM::STREAM_MODE_DAB, channel);
	qDebug() << "set Volume:         " << keyStoneCOMM.setVolume(7);
	qDebug() << "Volume:             " << keyStoneCOMM.volume();
	QThread::msleep(3500);
	qDebug() << "signal strength:    " << keyStoneCOMM.signalStrength(); // braucht delay

	//	return a.exec();
	return(0);
}
