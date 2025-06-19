//显示函数
int begin(); //显示主菜单
int majors(); //显示用户菜单
int regulate(); //显示管理员菜单

//系统函数
void initialize(); //初始化系统
void build(); //创建账户
void save(); //保存账户信息
void cleanup(); //清理内存

//用户函数
int enter1(); //用户登录
void deposit(int i); //存款
void withdraw(int i); //取款
void show(int i); //显示账户信息
void showRecord(int i); //显示交易记录
void amendPassword(int i); //修改密码

//管理员函数
bool enter2(); //管理员登录
void del(); //删除账户
void showAll(); //显示所有账户信息
void showAllRecord(); //显示所有交易记录
void amend(); //修改账户信息

