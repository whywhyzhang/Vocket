/*///////////////////

This is an instance of Demodulator, use DSTFT methods the decode FSK data.

*////////////////////

#include "Physical/Demodulator.h"

class DemodulatorDSTFT : public Demodulator {
	private:
		int Rate,Rate0,Rate1,WindowLen;

	public:

	private:
		// Check whether there is a long time for a signal (instead of noise), get the left and right of this signal.
		bool CheckHold(int * sig,int len,int pos,int & L,int & R);

		// Check wheter that is a start flag, (01010100).
		int CheckStr(int * sig,int len,int pos);

	public:
		DemodulatorDSTFT();
		DemodulatorDSTFT(int Rate,int Rate0,int Rate1,int WindowLen);

		int Set(int Rate,int Rate0,int Rate1,int WindowLen);

		int Data2Sig(DATA * in,int len,int * sig);
		// Find the position of start, -1 for not find.
		int FindStr(int * sig,int len);
		// Get the 01 final bits, nextstr is the position not be solved, and should be solved next times, and -1 for none.
		int Decode(int * sig,int len,BIT * out,int str,int & nextstr);

		int GetDataLen(int siglen);
		int GetSigLen(int datalen);
		int GetBitLen(int siglen);
		int GetLastdataLen();

		int SetBitrate(int bitrate);
};
