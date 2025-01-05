#pragma once

enum class CellType {
	None = -1,
	Empty = 0,
	Border,
	Block
};

// TODO: Color �� �ٸ� ����� �߰��� ���� �����ϵ��� struct�� ����
struct Cell {
	Cell(CellType type = CellType::Empty) : Type(type) {}

	static const Cell None;
	static const Cell Empty;
	static const Cell Border;

	CellType Type = CellType::Empty;
};