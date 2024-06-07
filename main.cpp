#include <iostream>
using namespace std;


// 自作クラス
class Enemy {
public:
	void Update();

	void kansu1();
	void kansu2();
	void kansu3();

	// メンバ関数ポインタのテーブルを参照するインデックス
	int index = 0;

private:
	// メンバ関数ポインタのテーブル
	static void (Enemy::* table[])();
};

void Enemy::kansu1() {
	cout << "敵の接近！" << endl;
}

void Enemy::kansu2() {
	cout << "敵の攻撃！" << endl;
}

void Enemy::kansu3() {
	cout << "敵の後退！" << endl;
}

void Enemy::Update() {

	// 関数ポインタのテーブルから関数を実行
	(this->*table[index])();

	int a;

	scanf_s("%d", &a);
	if (a == 0) {
		if (index == 2)
			index = 0;
		else
			index++;
	}

}

// staticで宣言したメンバ関数ポインタテーブルの実体
void (Enemy::* Enemy::table[])() = {
  &Enemy::kansu1, // インデックス番号0
  &Enemy::kansu2, // インデックス番号1
  &Enemy::kansu3, // インデックス番号2
};


int main()
{
	Enemy my;

	while(1)
  	  my.Update();

	return 0;
}