class Solution(object):
    def finalPositionOfSnake(self, n, commands):
        """
        :type n: int
        :type commands: List[str]
        :rtype: int
        """
        row=column=0
        for path in commands:
            if path=="RIGHT":
                column+=1
            elif path=="LEFT":
                column-=1
            elif path=="UP":
                row-=1
            else:
                row+=1

        return (row*n)+column                    