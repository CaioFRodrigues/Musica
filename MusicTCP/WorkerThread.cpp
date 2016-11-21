#include "stdafx.h"
#include "MusicTCP.h"
#include "MusicTCPDlg.h"
#include <iostream>
#include "CFugueLib.h"

WorkerThread::WorkerThread() {

}

BOOL WorkerThread::InitInstance()
{

}

void WorkerThread::playMusic() {

	if (CFugue::GetMidiOutPortCount() <= 0)
	{
		std::cerr << "No MIDI Output Ports found!";
		exit(-1);
	}

	std::cout << "Playing Notes..";
	CFugue::PlayMusicStringWithOpts(_T("C D E F G A B"), MIDI_MAPPER, 20);
}