#include<stdio.h>
void checkcomment(char s[])
{
    int cnt = 0;
    int len = strlen(s);
    for(int i=0;i<len;i++)
    {
        if(s[i]=='/')
        {
            if(i+1<len && s[i+1]=='/')
            {
                cnt = 1;
                break;
            }
            else if(i+1<len && s[i+1]=='*')
            {
                for(int j=i+1;j<len-1;j++)
                {
                    if(s[j]=='*'&&s[j+1]=='/')
                    {
                        cnt = 1; break;
                    }
                }
            }
        }
    }
    if(cnt==1)
        printf("Comment found\n");
    else   
        printf("Comment not found\n");
}
void countConsonantVowels(char s[])
{
	int vowel = 0, consonant = 0;
	int len = strlen(s);
	for(int i=0;i<len;i++)
	{
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')
			vowel++;
		else consonant++;
	}
	printf("Consonants = %d, Vowels = %d\n",consonant,vowels);
}
int main()
{
    char s[] = "It is comment/**/";
    checkcomment(s);
    countConsonantVowels(s);
    return 0;
}