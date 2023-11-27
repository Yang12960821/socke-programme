#include <iostream>
#include "RequestCodec.h"

using namespace std;

int main()
{
	// 编码
	RequestMsg req;
	req.cmdType = 100;
	strcpy(req.clientId, "hello");
	strcpy(req.authCode, "1111");
	strcpy(req.serverId, "22222");
	strcpy(req.r1, "abcdefg");

	Codec* codec = new RequestCodec(&req);
	// 调用编码函数
	char* outData;
	int len;
	codec->msgEncode(&outData, len);

	// ========================
	// 解码
	codec = new RequestCodec();
	RequestMsg* tmp = (RequestMsg*)codec->msgDecode(outData, len);
	cout << "cmdtype: " << tmp->cmdType << endl;
	cout << "serverID: " << tmp->serverId << endl;
	cout << "clientID: " << tmp->clientId << endl;
	cout << "r1: " << tmp->r1 << endl;

	return 0;
}