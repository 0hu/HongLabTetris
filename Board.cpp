#include "Board.h"

Board::Board(int width, int height) : _width(width), _height(height)
{
    _board.resize(_width * _height, CellState::Empty);

    // ����, ������ �� ����
    for (int y = 0; y < height; ++y) {
        SetState(0, y, CellState::Border);  // ���� ��
        SetState(_width - 1, y, CellState::Border);  // ������ ��
    }

    // �ٴ� ����
    for (int x = 0; x < _width; ++x)
        SetState(x, _height - 1, CellState::Border);
}

void Board::SetState(int x, int y, const CellState& state)
{
    _board[y * _width + x] = state;
}

Board::CellState Board::GetState(int x, int y) const
{
    return _board[y * _width + x];
}

int Board::CheckFullLines()
{
    int count = 0;
    for (int y = _height - 2; y >= 0; --y) {
        // �� ���� Block���� ��á�ٸ� Count + 1
        if (isFullLine(y)) {
            count++;
            removeLine(y); // �� ���� �����
            moveBlockDown(y); // y�� ���� block�� �� ĭ�� ������
        }
    }

    return count;
}

bool Board::isFullLine(int y)
{
    int x = 1;
    for (; x < _width - 1; ++x) {
        if (GetState(x, y) != CellState::Block)
            return false;
    }
    return true;
}

void Board::removeLine(int y)
{
    for (int x = 1; x < _width - 1; ++x)
        SetState(x, y, CellState::Empty);
}

void Board::moveBlockDown(int y)
{
    // y��° �� ���� ��� �� ĭ�� ������
    for (int ty = y; ty > 0; --ty) {
        for (int x = 1; x < _width - 1; ++x) {
            // ������ ���¸� ���� �ٷ� ����
            SetState(x, ty, GetState(x, ty - 1));
        }
    }

    // �ֻ�� ���� ���
    for (int x = 1; x < _width - 1; ++x) {
        SetState(x, 0, CellState::Empty);
    }
}
