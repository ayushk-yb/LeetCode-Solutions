import string

class Spreadsheet:

    def __init__(self, rows: int):
        self._cols = list(string.ascii_uppercase)
        self.spreadsheet = [[0 for _ in range(26)] for _ in range(rows)]
        

    def setCell(self, cell: str, value: int) -> None:
        col_idx = ord(cell[0]) - ord('A')
        self.spreadsheet[int(cell[1:]) - 1][col_idx] = value
        # print(self.spreadsheet[int(cell[1:]) - 1][col_idx])
        
    def _parse_cell(self, cell: str):
        col_idx = ord(cell[0]) - ord('A')
        row_idx = int(cell[1:]) - 1
        return row_idx, col_idx

    def resetCell(self, cell: str) -> None:
        row_idx, col_idx = self._parse_cell(cell)
        self.spreadsheet[row_idx][col_idx] = 0
        

    def getValue(self, formula: str) -> int:
        expression = formula[1:]
        parts = expression.split('+')
        total = 0
        # print(parts)
        for part in parts:
            if part.isdigit():
                total += int(part)
            else:
                row_idx, col_idx = self._parse_cell(part)
                total += self.spreadsheet[row_idx][col_idx]
                # print(total)
        
        return total


# Your Spreadsheet object will be instantiated and called as such:
# obj = Spreadsheet(rows)
# obj.setCell(cell,value)
# obj.resetCell(cell)
# param_3 = obj.getValue(formula)