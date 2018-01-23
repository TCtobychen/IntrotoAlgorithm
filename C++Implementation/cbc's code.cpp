/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
void prtpic(int wrg)//ª≠–°»À£¨±‰¡øŒ™¥ÌŒÛ¥Œ ˝
{
    switch (wrg)
    {
        case 0:
            printf("------\n|\n|\n|\n|\n|\n|_____\n|     |____\n|__________|\n");
            break;
        case 1:
            printf("------\n|  |\n|  0\n|\n|\n|\n|_____\n|     |____\n|__________|\n");
            break;
        case 2:
            printf("------\n|  |\n|  0\n| /\n|\n|\n|_____\n|     |____\n|__________|\n");
            break;
        case 3:
            printf("------\n|  |\n|  0\n| /|\n|  |\n|\n|_____\n|     |____\n|__________|\n");
            break;
        case 4:
            printf("------\n|  |\n|  0\n| /|\\ \n|  |\n|\n|_____\n|     |____\n|__________|\n");
            break;
        case 5:
            printf("------\n|  |\n|  0\n| /|\\ \n|  |\n| /\n|_____\n|     |____\n|__________|\n");
            break;
        case 6:
            printf("------\n|  |\n|  0\n| /|\\ \n|  |\n| / \\\n|_____\n|     |____\n|__________|\n");
            break;
    }
}
void crtwd(char wd[100])//¥”µ•¥ ø‚÷–ÀÊª˙…˙≥…“ª∏ˆ”¢”Ôµ•¥
{
    char wdlist[][100] = { "advanturous","bibliography","capitulate", "dart", "eligibility", "fabric", "growl", "hysterical", "idea", "jealous", "kitten", "legitimate", "malignant", "namination", "overtake", "pathetic", "quaint", "rampage", "scarlet", "tamper", "ubiquitous", "velocity", "wade", "xerox", "yacht", "zoological" };
    srand(time(NULL));
    int x = rand() % 26;
    char *p, *q;
    p = wdlist[x];
    q = wd;
    while (*p != '\0') {
        *q = *p;
        p++;
        q++;
        *q = '\0';
    }
}
void crtblk(char wd[100], char blk[100])//¥¥Ω®“ª∏ˆ”√ªßø¥µ√µΩµƒø’∏Ò
{
    char *p, *q;
    p = wd;
    q = blk;
    while (*p != '\0') {
        *q = '_';
        q++;
        *q = ' ';//Œ™¡Àø… ”ªØ≤Ÿ◊˜£¨√ø“ª∏ˆœ¬ªÆœﬂ∫Û‘ˆº”“ª∏ˆø’∏Ò∏Ùø™
        q++;
        p++;
        *q = '\0';
    }
}
int wrgchkch(char wd[100], char blk[100], char ch, int wrg)//ºÏ≤Èword÷– «∑Ò”–”Îch“ª—˘µƒ◊÷∑˚£¨»Áπ˚”–£¨–ﬁ∏ƒblk£ª»Áπ˚√ª”–£¨wrg+1
{
    char *p, *q;
    int chk = 0;
    p = wd;
    q = blk;
    while (*p != '\0') {
        if (*p == ch)
        {
            *q = ch;
            chk++;
        }
        p++;
        q += 2;
    }
    if (chk == 0) {
        wrg += 1;
    }
    return wrg;
}
bool chkblk(char blk[100])//ºÏ—Èblk÷–µƒ◊÷ƒ∏ «∑Ò±ª»´≤ø≤¬≥ˆ
{
    char *p;
    int chk = 0;
    p = blk;
    while (*p != '\0') {
        if (*p == '_') {
            chk++;
        }
        p++;
    }
    if (chk)
        return false;
    else
        return true;
}
bool chkgus(char gus[100], char ch)//”√”⁄ºÏ—È «∑Ò ‰»Î¡À“ª∏ˆ÷ÿ∏¥µƒ◊÷∑˚
{
    int chk = 0;
    char *p;
    p = gus;
    while (*p != '\0') {
        if (*p == ch)
            chk++;
        p++;
    }
    if (chk)
        return true;
    else
        return false;
}
void clrgus(char gus[100])//÷ÿ÷√gus
{
    for (int i = 0; i < 100;) {
        gus[i] = ' ';
        i++;
        gus[i] = '\0';
    }
}
int main()
{
    int wrg;//¥ÌŒÛ¥Œ ˝
    int temwrg;//‘› ±¥¢¥Êµƒ¥ÌŒÛ¥Œ ˝£¨”√”⁄”Î≈–∂œ∫Ûµƒ¥ÌŒÛ¥Œ ˝Ω¯––±»Ωœ
    char wd[100];//“™≤¬µƒµ•¥
    char blk[100];//ø’∏Ò
    char ch;// ‰»Îµƒ◊÷∑˚
    char input[100];//”√”⁄ºÏ≤‚ ‰»Îµƒ◊÷∑˚ «∑Ò∫œ∑®
    char time[100];//”√”⁄ºÏ≤‚÷ÿ–¬ø™ ºÀ˘ ‰»Îµƒ◊÷∑˚ «∑Ò∫œ∑®
    char gus[100];//”√”⁄ ‰≥ˆ≤¬≤‚µƒ◊÷∑˚–Ú¡–£¨≤¢ºÏ≤‚ «∑Ò ‰»Î¡À“ª∏ˆ÷Æ«∞≤¬π˝µƒ◊÷∑˚
    int i;// ‰»Î◊÷∑˚¥Œ ˝£¨”√”⁄Ω´ ‰»Îµƒ◊÷∑˚ ‰»Îgus÷–
    gus[0] = '\0';
    printf("Welcome to the game Hangman.\n");//≥ı ºª≠√Ê
    while (1) {
        printf("Let's start.\n");
        crtwd(wd);//÷ÿ÷√µ•¥
        wrg = 0;//÷ÿ÷√¥ÌŒÛ¥Œ ˝
        prtpic(wrg);//ª≠≥ˆ≥ı ºΩ –Ãº‹
        crtblk(wd, blk);//÷ÿ÷√ø’∏Ò
        clrgus(gus);//÷ÿ÷√gus–Ú¡–
        printf("Here is the blank.\n%s\n", blk);
        i = 0;//÷ÿ÷√ ‰»Î¥Œ ˝
        while (wrg != 6) {
        begin://≥ı ºµ„
            printf("Please enter a character.\n");
            scanf("%s", input);
            for (int i = 0; i < 100; i++)//»•≥˝ ‰»Î÷–µƒø’∏Ò
            {
                while (input[i] == ' ') {
                    for (int j = i; j < 100; j++)
                        input[j] = input[i + 1];
                }
            }
            ch = input[0];
            if (input[1] != '\0') //ºÏ—È «∑Ò ‰»Î¡À“ª¥Æ◊÷∑˚
            {
                printf("Please enter one character at one time.\n");
                goto begin;//ªÿµΩ≥ı ºµ„
            }
            if (ch < 'A' || ch > 'z' || (ch > 'Z' && ch < 'a')) //ºÏ—È «∑Ò ‰»Î”¢Œƒ◊÷∑˚
            {
                printf("The character you entered before is invalid, please try again.\n");
                goto begin;//ªÿµΩ≥ı ºµ„
            }
            if (ch <= 'Z') //–ﬁ’˝¥Û–°–¥
            {
                ch += 32;
            }
            if (chkgus(gus, ch)) //ºÏ—È «∑Ò ‰»Î¡À“ª∏ˆ÷ÿ∏¥µƒ◊÷ƒ∏
            {
                printf("You have entered this character already.\n");
                goto begin;//ªÿµΩ≥ı ºµ„
            }
            gus[i] = ch;//Ω´æ≠ºÏ—Èµƒ◊÷∑˚ch ‰»Îgus
            i++;
            gus[i] = '\0';
            temwrg = wrg;
            wrg = wrgchkch(wd, blk, ch, wrg);//ºÏ—Èwd «∑Ò”–”Îchœ‡Õ¨µƒ◊÷∑˚
            if (temwrg == wrg) //¥˙±Ì√ª”– ‰¥Ì◊÷ƒ∏
            {
                printf("This character is in the word.\n");
                printf("%s\n", blk);
            }
            else //¥˙±Ì ‰¥Ì◊÷ƒ∏
            {
                printf("I'm sorry. Try another character.\n%s\n", blk);
                prtpic(wrg);
            }
            if (chkblk(blk))//æ≠ºÏ—Èµ•¥ “—Ω‚ø™£¨”Œœ∑ §¿˚
            {
                printf("Conguradulations.\nYou figured it out.\n");
                printf("The characters you guessed are %s.\n", gus);
                break;
            }
        }
        if (wrg == 6)//6¥Œ¥ÌŒÛ÷Æƒ⁄√ª”–Ω‚ø™µ•¥ £¨”Œœ∑ ß∞‹
        {
            printf("Game over.\nYour answer is %s .\nThe word is %s .\n", blk, wd);
            printf("The characters you guessed are %s.\n", gus);
        }
        printf("Do you want to play again?\n1 for YES, and 0 for NO.\n");
    qs://◊˜Œ™Œ Ã‚µƒ≥ı ºµ„
        scanf("%s", time);
        if (time[0] == '1')//ºÃ–¯
            ;
        else if (time[0] == '0')//≤ªºÃ–¯
        {
            printf("OK. See you then.\n");
            //clrgus(gus);
            break;
        }
        else//ºÏ—È ‰»Î «∑Ò∫œ∑®
        {
            printf("The input is invalid. Please try again.\n");
            goto qs;//ªÿµΩŒ Ã‚≥ı ºµ„
        }
    }
}*/
