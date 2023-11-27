#include <iostream>
#include <occi.h>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;
using namespace oracle::occi;

int main()
{
	//��ʼ������
	Environment *env = Environment::createEnvironment();
	if (env == NULL)
	{
		cout << "createEnvironment error" << endl;
		return -1;
	}

	//����oracle���ݿ�
	string usr = "scott";
	string passwd = "tiger";
	string connstr = "192.168.10.145:1521/orcl";
	Connection *conn = env->createConnection(usr, passwd, connstr);
	if (conn == NULL)
	{
		cout << "connect database error" << endl;
		return -1;
	}

	//ִ�в������
	Statement *stmt = conn->createStatement("insert into dept values(79, 'nongwu', 'tianjin')");
	stmt->executeUpdate();

	//�ر����ݿ�����
	env->terminateConnection(conn);

	//�ر��ͷ���Դ
	Environment::terminateEnvironment(env);

	return 0;
}