#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <openssl/sha.h>
using namespace std;
int main()
{
	char data[1024] = "xiaowu,hello world";
	int len = strlen(data);
	unsigned char md[SHA512_DIGEST_LENGTH] = {0};

	//int SHA512_Init(SHA512_CTX *c);
	//int SHA512_Update(SHA512_CTX *c, const void *data, size_t len);
	//int SHA512_Final(unsigned char *md, SHA512_CTX *c);
	
	SHA512_CTX c;
	SHA512_Init(&c);
	SHA512_Update(&c, data, len);
	SHA512_Final(md, &c);
	//cout << md << endl;

	char buf[SHA512_DIGEST_LENGTH * 2 + 1] = { 0 };
	for (int i = 0; i < SHA512_DIGEST_LENGTH; i++)
	{
		sprintf(&buf[i*2], "%02x", md[i]);
	}
	cout << buf << endl;

	//unsigned char *SHA512(const unsigned char *d, size_t n, unsigned char *md);
	memset(md, 0x00, sizeof(md));
	unsigned char data1[1024]= "xiaowu,hello world";
	SHA512(data1, len, md);
	memset(buf, 0x00, sizeof(buf));
	for (int i = 0; i < SHA512_DIGEST_LENGTH; i++)
	{
		sprintf(&buf[i * 2], "%02x", md[i]);
	}
	cout << buf << endl;

	
	
	return 0;
}