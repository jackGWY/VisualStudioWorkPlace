#include<Windows.h>
//6 �����ڹ���
/*

*/
LRESULT CALLBACK WindowProc(
	HWND   hwnd, //��Ϣ�����ڵĴ��ھ��
	UINT   uMsg, //�������Ϣ���� WM_XXX ��Ϣ��
	WPARAM wParam,// ���̵ĸ�����Ϣ
	LPARAM lParam //���ĸ�����Ϣ
	)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		DestroyWindow(hwnd); // destroyWindow ������ϢWM_DESTROY

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_LBUTTONDOWN:
	{
		int xPos = LOWORD(lParam);
		int yPos = HIWORD(lParam);
		MessageBox(hwnd, TEXT("aaa"), TEXT("��������"), MB_OK);
		break;
	}
	}

	//����ֵ��Ĭ�ϴ���ʽ
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}
// WINAPI����__stdcall
int WINAPI WinMain(
	HINSTANCE hInstance,   // Ӧ�ó�����
	HINSTANCE hPrevInstance, // ��һ��Ӧ�ó���������win32�� ��һ��Ϊnull����������
	LPSTR lpCmdLine, // char* argv[]
	int nShowCmd) // ��ʾ�����󻯣���С��������
{
	 //1 ���һ������
	// 2.ע�ᴰ��
	//3. ����һ������
	// 4.��ʾ�͸���
	// 5.ͨ��ѭ��ȡ��Ϣ
	// 6.������Ϣ�����ڹ���

	// 1.��ƴ���
	WNDCLASS wc;
	wc.cbClsExtra = 0; // ��Ķ����ڴ�
	wc.cbWndExtra = 0; // ���ڶ�����ڴ�
	wc.hbrBackground =(HBRUSH) GetStockObject(WHITE_BRUSH);//���ñ���
	wc.hCursor = LoadCursor(NULL,IDC_HAND); //���ù��,�����һ������ΪNULL
	wc.hIcon = LoadIcon(NULL,IDI_ERROR);
	wc.hInstance = hInstance;//Ӧ�ó������� ����winMain�е��βμ���
	wc.lpfnWndProc = WindowProc; //���ڹ��̣��ص�����
	wc.lpszClassName = TEXT("WIN");//ָ����������
	wc.lpszMenuName = NULL;
	wc.style = 0;//��ʾ��� 0 ������

	//2.ע�ᴰ��
	RegisterClass(&wc);
	//3.��������
	/*
	lpClassName, ����
	lpWindowName, ������
	dwStyle, 
	x,����
	y,
	nWidth, ���
	nHeight,
	hWndParent,������NULL
	hMenu, �˵�NULL
	hInstance,  ʵ����� hInstance
	lpParam ����ֵ ��긽��ֵ NULL
	*/
	HWND hwnd=CreateWindow(wc.lpszClassName, TEXT("WINDOW"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);
	//4. ��ʾ�͸���
	ShowWindow(hwnd, SW_SHOWNORMAL);
	UpdateWindow(hwnd);
	//ͨ��ѭ��ȡ��Ϣ
	/*
	HWND   hwnd; �����ھ��
	UINT   message; �������Ϣ����
	WPARAM wParam; ������Ϣ�����̵���Ϣ
	LPARAM lParam; ������Ϣ�������Ϣ������Ҽ�
	DWORD  time; ��Ϣ������ʱ��
	POINT  pt; ������Ϣ�������Ϣ��x,y �������Ϣ
	DWORD  lPrivate;
	*/
	MSG msg;
	while (1)
	{
		/*
		LPMSG lpMsg,  ��װ�õ���Ϣ��ָ��
		HWND  hWnd, ���񴰿ڣ����ھ��
		UINT  wMsgFilterMin, ��С�����Ĺ�����Ϣһ������0
		UINT  wMsgFilterMax  ��0������������Ϣ
		*/
		if (GetMessage(&msg, NULL, 0, 0)== FALSE)
		{
			break;
		}
		// ������Ϣ
		TranslateMessage(&msg);
		//�ַ���Ϣ
		DispatchMessage(&msg);
	}

}