#include <iostream>
using namespace std;


// ����N���X
class Enemy {
public:
	void Update();

	void kansu1();
	void kansu2();
	void kansu3();

	// �����o�֐��|�C���^�̃e�[�u�����Q�Ƃ���C���f�b�N�X
	int index = 0;

private:
	// �����o�֐��|�C���^�̃e�[�u��
	static void (Enemy::* table[])();
};

void Enemy::kansu1() {
	cout << "�G�̐ڋ߁I" << endl;
}

void Enemy::kansu2() {
	cout << "�G�̍U���I" << endl;
}

void Enemy::kansu3() {
	cout << "�G�̌�ށI" << endl;
}

void Enemy::Update() {

	// �֐��|�C���^�̃e�[�u������֐������s
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

// static�Ő錾���������o�֐��|�C���^�e�[�u���̎���
void (Enemy::* Enemy::table[])() = {
  &Enemy::kansu1, // �C���f�b�N�X�ԍ�0
  &Enemy::kansu2, // �C���f�b�N�X�ԍ�1
  &Enemy::kansu3, // �C���f�b�N�X�ԍ�2
};


int main()
{
	Enemy my;

	while(1)
  	  my.Update();

	return 0;
}