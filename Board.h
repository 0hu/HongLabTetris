#pragma once
#include <vector>

// ��Ʈ������ ����� �Ǵ� Board Ŭ����
class Board
{
public:
	enum class CellState {
		Empty = 0,
		Border,
		Block
	};
	
	Board(int width, int height);
	
	void SetState(int x, int y, const CellState& state);
	CellState GetState(int x, int y) const;

	// board���� Block���� �� �� ���� ���� �ľ� �� �� �� ���� ����
	int CheckFullLines();
private:
	// �� ���� ��á���� Ȯ��
	bool isFullLine(int y);
	// �� �� ����
	void removeLine(int y);
	// y��° �� ���� ��� Block�� �Ʒ��� ��ĭ�� �̵�
	void moveBlockDown(int y);


private:
	int _width = 0;
	int _height = 0;
	std::vector<CellState> _board;
};

