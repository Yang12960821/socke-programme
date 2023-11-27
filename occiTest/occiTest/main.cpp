#include <iostream>
#include <occi.h>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;
using namespace oracle::occi;

int main()
{
	//初始化环境
	Environment *env = Environment::createEnvironment();
	if (env == NULL)
	{
		cout << "createEnvironment error" << endl;
		return -1;
	}

	//连接oracle数据库
	string usr = "scott";
	string passwd = "tiger";
	string connstr = "192.168.10.145:1521/orcl";
	Connection *conn = env->createConnection(usr, passwd, connstr);
	if (conn == NULL)
	{
		cout << "connect database error" << endl;
		return -1;
	}

	//执行插入操作
	Statement *stmt = conn->createStatement("insert into dept values(79, 'nongwu', 'tianjin')");
	stmt->executeUpdate();

	//关闭数据库连接
	env->terminateConnection(conn);

	//关闭释放资源
	Environment::terminateEnvironment(env);

	return 0;
}