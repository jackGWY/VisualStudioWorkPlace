#include<Windows.h>
//6 处理窗口过程
/*

*/
LRESULT CALLBACK WindowProc(
	HWND   hwnd, //消息所属于的窗口句柄
	UINT   uMsg, //具体的消息名称 WM_XXX 消息名
	WPARAM wParam,// 键盘的附件消息
	LPARAM lParam //鼠标的附件消息
	)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd); // destroyWindow 发送消息WM_DESTROY

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);
		MessageBox(hwnd, TEXT("aaa"), TEXT("鼠标键按下"), MB_OK);
		break;
	}
	}

	//返回值用默认处理方式
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
// WINAPI代表__stdcall
int WINAPI WinMain(
	HINSTANCE hInstance,   // 应用程序句柄
	HINSTANCE hPrevInstance, // 上一个应用程序句柄，在win32下 ，一般为null，不起作用
	LPSTR lpCmdLine, // char* argv[]
	int nShowCmd) // 显示命令，最大化，最小化，正常
{
	 //1 设计一个窗口
	// 2.注册窗口
	//3. 创建一个窗口
	// 4.显示和更新
	// 5.通过循环取消息
	// 6.处理消息，窗口过程

	// 1.设计窗口
	WNDCLASS wc;
	wc.cbClsExtra = 0; // 类的额外内存
	wc.cbWndExtra = 0; // 窗口额外的内存
	wc.hbrBackground =(HBRUSH) GetStockObject(WHITE_BRUSH);//设置背景
	wc.hCursor = LoadCursor(NULL,IDC_HAND); //设置光标,如果第一个参数为NULL
	wc.hIcon = LoadIcon(NULL,IDI_ERROR);
	wc.hInstance = hInstance;//应用程序句柄， 闯入winMain中的形参即可
	wc.lpfnWndProc = WindowProc; //窗口过程，回调函数
	wc.lpszClassName = TEXT("WIN");//指定窗口类名
	wc.lpszMenuName = NULL;
	wc.style = 0;//显示风格 0 代表风格

	//2.注册窗口
	RegisterClass(&wc);
	//3.创建窗口
	/*
	lpClassName, 类名
	lpWindowName, 标题名
	dwStyle, 
	x,坐标
	y,
	nWidth, 宽高
	nHeight,
	hWndParent,父窗口NULL
	hMenu, 菜单NULL
	hInstance,  实例句柄 hInstance
	lpParam 附加值 鼠标附加值 NULL
	*/
	HWND hwnd=CreateWindow(wc.lpszClassName, TEXT("WINDOW"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	//4. 显示和更新
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	//通过循环取消息
	/*
	HWND   hwnd; 主窗口句柄
	UINT   message; 具体的消息名称
	WPARAM wParam; 附加消息，键盘的消息
	LPARAM lParam; 附加消息，鼠标消息，左键右键
	DWORD  time; 消息产生的时间
	POINT  pt; 附加消息，鼠标消息，x,y 坐标点信息
	DWORD  lPrivate;
	*/
	MSG msg;
	while (1)
	{
		/*
		LPMSG lpMsg,  封装好的消息，指针
		HWND  hWnd, 捕获窗口，窗口句柄
		UINT  wMsgFilterMin, 最小和最大的过滤消息一般填入0
		UINT  wMsgFilterMax  填0代表捕获所有消息
		*/
		if (GetMessage(&msg, NULL, 0, 0)== FALSE)
		{
			break;
		}
		// 翻译消息
		TranslateMessage(&msg);
		//分发消息
		DispatchMessage(&msg);
	}

}