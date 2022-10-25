#include<iostream>
#include<cstdlib>
#include<ctime>
#include"MyLib.h"

#define Max 100

using namespace std;

int sl = 6;// số lượng tạm thời của rắn
int foodX;
int foodY;

			// nguyên mẫu hàm //
void VeTuong();
void KhoiTaoRan(int ToaDoX[], int ToaDoY[]);
void VeRan(int ToaDoX[],int ToaDoY[]);
void DiChuyen(int ToaDoX[], int ToaDoY[]);
bool KiemTra(int dau1, int dau2, int ToaDoX[], int ToaDoY[], int x);
bool XuLyGameOver(int ToaDoX[], int ToaDoY[]);
void ThucAn(int ToaDoX[], int ToaDoY[]);
void XuLyConRan(int ToaDoX[], int ToaDoY[], int &Diem);
void Menu(int ToaDoX[], int ToaDoY[]);
			//================//

int main() {
	int ToaDoX[Max], ToaDoY[Max];
	Menu(ToaDoX, ToaDoY);
	gotoXY(1,26);
	return 0;
}

void VeTuong() {
	int x = 10, y = 1;
	SetColor(3);
	for (int i = 1; i <= 26; i++) {
		gotoXY(x, y);
		for (int j = 1; j <= 100; j++) {
			if (i == 1 || i == 26) {
				cout << "#";
			}
			else if (j == 1 || j == 100) {
				cout << "#";
			}
			else
				cout << " ";
		}
		y++;
	}
}

void KhoiTaoRan(int ToaDoX[], int ToaDoY[]) {
	int x = 50, y = 13;// tọa độ tạm thời của rắn
	for (int i = 0; i < sl; i++) {
		ToaDoX[i] = x;
		ToaDoY[i] = y;
		x--;
	}
}

void VeRan(int ToaDoX[], int ToaDoY[] ) {
	for (int i = 0; i < sl; i++) {
		gotoXY(ToaDoX[i], ToaDoY[i]);
		if (i == 0) {
			cout << "O";
		}
		else
			cout << "o";
	}
}

void DiChuyen(int ToaDoX[],int ToaDoY[]) {
	int check = 0;
	//0 là đi qua phải == x++;
	//1 là đi qua trái == x--;
	//2 là đi lên == y--;
	//3 là đi xuống == y++;
	int x = 50, y = 13;// tọa độ tạm thời của rắn phải có để cập nhật lại tọa độ
	int MangPhuX[Max], MangPhuY[Max];// phải có để lưu trữ phần tử trước đó để xóa
	int Diem = 0;// Điểm thưởng

	while (true) {
		gotoXY(80, 0);
		cout << "Diem so: " << Diem;
		//cho tất cả phần tử ở mảng ToaDoX và ToaDoY vào mảng phụ
		for (int i = 0; i < sl; i++) {
			MangPhuX[i] = ToaDoX[i];
			MangPhuY[i] = ToaDoY[i];
		}
		//xóa
		for (int i = 0; i < sl; i++) {
			gotoXY(MangPhuX[i], MangPhuY[i]);
			cout << " ";
		}

		// chỉnh màu
		SetColor(6);
		//o++;
		
		// lấy kí tự truyền vào
		if (_kbhit()) {
			char kitu = _getch();
			if (kitu == 'd') {
				check = 0;
			}
			else if (kitu == 'a') {
				check = 1;
			}
			else if (kitu == 'w') {
				check = 2;
			}
			else if (kitu == 's') {
				check = 3;
			}
		}
		//di chuyển đầu
		if (check == 0) {
			if (x + 1 != ToaDoX[1]) {
				x++;
			}
			else {
				check = 1;// nếu bằng thì vẫn đi tiếp
				x--;
			}
			ToaDoX[0] = x;
		}
		else if (check == 1) {
			if (x - 1 != ToaDoX[1]) {
				x--;
			}
			else {
				check = 0;
				x++;
			}
			ToaDoX[0] = x;
		}
		else if (check == 2) {
			if (y - 1 != ToaDoY[1]) {
				y--;
			}
			else {
				check = 3;
				y++;
			}
			ToaDoY[0] = y;
		}
		else if (check == 3) {
			if (y + 1 != ToaDoY[1]) {
				y++;
			}
			else {
				check = 2;
				y--;
			}
			ToaDoY[0] = y;
		}
		//những phần tử còn lại thì giống phần tử lúc chưa thay đổi + Dài ra
		for (int i = 1; i < sl; i++) {
			ToaDoX[i] = MangPhuX[i - 1];
			ToaDoY[i] = MangPhuY[i - 1];
		}
		
		// xử lý con rắn dài ra
		XuLyConRan(ToaDoX, ToaDoY, Diem);
		// xuất con rắn
		VeRan(ToaDoX, ToaDoY);
		Sleep(100);
		if (Diem == 200) {
			gotoXY(25, 0);
			cout << " YOU WIN  ";
			break;
		}
		if (XuLyGameOver(ToaDoX, ToaDoY))
			break;
	}
}

bool KiemTra(int dau1,int dau2, int ToaDoX[], int ToaDoY[], int x) {
	//x ở đây là kiểm tra từ đâu
	//kiểm tra con rắn thì từ 3, kiểm tra thức ăn thì 0
	for (int i = x; i < sl; i++) {
		if (dau1 == ToaDoX[i] && dau2 == ToaDoY[i])
			return true;
	}
	return false;
}

bool XuLyGameOver(int ToaDoX[], int ToaDoY[]) {
	bool thu1 = false, thu2 = false;
	if (KiemTra(ToaDoX[0],ToaDoY[0],ToaDoX,ToaDoY,1))
		thu1 = true;
	if ((ToaDoX[0] == 10) || (ToaDoX[0] == 109) || (ToaDoY[0] == 1) || (ToaDoY[0] == 26))
		thu2 = true;
	if (thu1 || thu2) {
		gotoXY(25, 0);
		cout << "Game Over you BITCH   ";
		return true;
	}
	return false;
}

void ThucAn(int ToaDoX[], int ToaDoY[]) {
	srand(time(NULL));// làm cho thay đổi giá trị
	// công thức là: rand() % (max - min + 1) + min;
	do {
		//Thức ăn của tọa độ x
		foodX = rand() % (99 - 11 + 1) + 11;
		//Thức ăn của tọa độ y
		foodY = rand() % (25 - 2 + 1) + 2;
	} while (KiemTra(foodX,foodY,ToaDoX,ToaDoY,0));
	//Thức ăn không được trùng với con rắn ==> Phải kiểm tra
	//0 ở đây là kiểm tra từ đầu
	gotoXY(foodX, foodY);
	SetColor(7);
	cout << "*";
}

void XuLyConRan(int ToaDoX[], int ToaDoY[], int &Diem) {
	if (ToaDoX[0] == foodX && ToaDoY[0] == foodY) {
		sl++;
		Diem += 10;
		ThucAn(ToaDoX, ToaDoY);
	}
}

void Menu(int ToaDoX[], int ToaDoY[]) {
	int LuaChon;
	while (true) {
		system("cls");
		sl = 6;
		SetColor(7);
		cout << "\n\t============MENU=============";
		cout << "\n\t\t1.Choi game";
		cout << "\n\t\t2.Huong dan";
		cout << "\n\t\t3.Thoat Game";
		cout << "\n\t============END==============";
		cout << "\nxin moi nhap lua chon: ";
		cin >> LuaChon;
		switch (LuaChon) {
		case 1: {
			system("cls");
			VeTuong();
			KhoiTaoRan(ToaDoX, ToaDoY);
			ThucAn(ToaDoX, ToaDoY);
			DiChuyen(ToaDoX, ToaDoY);
			system("pause");
			break;
		}
		case 2: {
			cout << "\ncoi huong dan lam moe gi choi de\n";
			system("pause");
			break;
		}
		case 3: {
			return;
		}
		default: {
			cout << "ao game a lam gi co lua chon khac";
			system("pause");
		}
		}
	}
}
