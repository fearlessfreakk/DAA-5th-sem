#include <stdio.h>
#include <string.h>

int lcs(char *s1, char *s2)
{
    int r = strlen(s1)+1;
    int c = strlen(s2)+1;
    int mat[r][c];

    for (int i=0; i<r; i++)
    {
        for (int j=0; j<c; j++)
        {
            if (i==0 || j==0) mat[i][j] = 0;

            else if (s1[i-1] == s2[j-1]) mat[i][j] = mat[i-1][j-1] + 1;
            
            else mat[i][j] = (mat[i-1][j] > mat[i][j-1]) ? mat[i-1][j] : mat[i][j-1];
        }
    }

    int i = r-1, j = c-1;
    int length = mat[i][j];
    char seq[length+1];
    seq[length] = '\0';

    while (i>0 && j> 0)
    {
        if (s1[i-1] == s2[j-1])
        {
            seq[length-1] = s1[i-1];
            i--; j--; length--;
        }
        else if (mat[i-1][j] > mat[i][j-1]) i--;
        else j--;
    }

    printf("The sequence is : %s\n", seq);
    return mat[r-1][c-1];
}

int main()
{
    char s1[100], s2[100];
    printf("Enter first string : ");
    scanf("%s", s1);
    printf("Enter second string : ");
    scanf("%s", s2);

    int lcsLen = lcs(s1, s2);
    printf("Length of LCS = %d\n", lcsLen);

    return 0;
}
