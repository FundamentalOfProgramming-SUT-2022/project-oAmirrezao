#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAX_CMD 10
#define MAX 1000
int check = 1;
char create_cmd[] = "create";       // 6 harf
char str_cmd[] = "--str";           // 5 harf
char file_cmd[] = "--file";      // 6 harf
char pos_cmd[] = "--pos";        // 5 harf
char size_cmd[] = "-size";       // 5 harf
char insertstr_cmd[] = "insertstr"; // 9 harf
char cat_cmd[] = "cat";             // 3 harf
char remove_cmd[] = "removestr"; // 9 harf
char exit_cmd[] = "exit";           // 4 harf
FILE* clipboard;


int how_many_lines(char content[])
{
    int lines = 1;

    for (int i = 0; content[i] != '\0'; i++)
    {
        if (content[i] == 10)
        {
            lines++;
        }
    }

    return lines;
}

int how_many_index_in_line(char content[], int line)
{
    int index1 = 0;
    int lines = 1;
    for(int i = 0; content[i]!='\0'; i++)
    {
        if(lines == line)
        {
                index1++ ;
        }
        if(content[i] == 10)
        {
            lines++ ;
        }
    }

    return index1;
}

int index_in_str(char content[])
{
    int i;
    for(i = 0; content[i]!='\0'; i++)
    {
    }
    return i-1;
}

void createfile()
{
    char file[MAX_CMD];
    scanf("%s", file);
    // check = 1;
    int check2 = 1;
    check = 1;
    char file_path[MAX] = "C:\\Users\\PC\\Desktop\\root\\";
    getchar();
    char c = getchar();
    printf("%c", c);
    int a = 25;
    if(c == '\"')
    {
        file_path[a];
        c = getchar();
        a++ ;
    }
    else
    {
    file_path[25] = c;
    scanf("%s", file_path + 26);
    FILE *fptr = fopen(file_path, "r");
        if(fptr != NULL)
        {
            printf("in file vogood dare!\n");
            fclose(fptr);
        }
        else
        {
            fclose(fptr);
            fptr = fopen(file_path, "w");
            printf("file dorost shod\n");
            fclose(fptr);
        }
        check2 = 0;
    }
    file_path[a] = '\0';
    if(check2)
    {
        FILE* fptr = fopen(file_path, "r");
        {
            if(fptr != NULL)
            {
                printf("in file vogood dare!\n");
                fclose(fptr);
            }
            else
            {
                fclose(fptr);
                fptr = fopen(file_path, "w");
                printf("file dorost shod\n");
            }
        }
    }
}

void insert()
{
    char file[MAX_CMD];
    scanf("%s", file);
    getchar();
    if (!strcmp(file, "--file"))
    {
        check = 1;
        char file_name[MAX];
        char c1 = getchar();
        if(c1 == '\"')
        {
        int d = 0;
        char ch1 = getchar();
        while(ch1 != '\"')
        {
            file_name[d] = ch1;
            d++ ;
            ch1 = getchar();
        }
        file_name[d] = '\0';
        FILE *fptr = fopen(file_name, "r");

        if (fptr == NULL)
        {
            printf("there is no such file.\n");
            fclose(fptr);
        }
        else
        {
            char str[MAX_CMD];
            scanf("%s", str);
            getchar();
            if (!strcmp(str, "--str"))
            {
                char text_to_insert[MAX];
                char c = getchar();
                if(c == '\"')
                {
                    int b = 0;
                    char ch = getchar();
                    while(ch != '\"')
                    {
                        text_to_insert[b] = ch;
                        b++ ;
                        ch = getchar();
                    }
                    text_to_insert[b] = '\0';
                    int index1, line1 , index, line;
                    scanf("%d:%d", &line1, &index1);
                    char str[MAX];
                    fscanf(fptr, "%[^\0]", str);
                    fclose(fptr);
                    fptr = fopen(file_name, "w");
                    line = how_many_lines(str);
                    if(line1<=line)
                    {
                        index = how_many_index_in_line(str, line1);
                    }
                    if(line1>line)
                    {
                        printf("line out of bonds!\n");//haminja tabe ro tamom kon
                        fclose(fptr);
                    }
                    else if(index1>index)
                    {
                        printf("index out of bonds!\n");
                        fclose(fptr);
                    }
                    else
                    {
                        int inds = index_in_str(str);
                        char str_final[MAX];
                        int i, j, k;
                        for(i = 0; i<inds; i++)
                        {
                            str_final[i] = str[i];
                        }
                        for(j = inds; j<(inds+strlen(text_to_insert)); j++)
                        {
                            str_final[j] = text_to_insert[j-inds];
                        }
                        for(k = (inds+strlen(text_to_insert)); str[k]!='\0'; k++)
                        {
                            str_final[k] = str[k-strlen(text_to_insert)];
                        }
                        str_final[k] = '\0';
                        fprintf(fptr, "%s", str_final);
                        fclose(fptr);
                    }
                }
                else
                {
                    text_to_insert[0] = c;
                    scanf("%s", text_to_insert + 1);
                    int index1, line1 , index, line;
                    scanf("%d:%d", &line1, &index1);
                    char str[MAX];
                    fscanf(fptr, "%[^\0]", str);
                    fclose(fptr);
                    fptr = fopen(file_name, "w");
                    line = how_many_lines(str);
                    if(line1<=line)
                    {
                        index = how_many_index_in_line(str, line1);
                    }
                    if(line1>line)
                    {
                        printf("line out of bonds!\n");//haminja tabe ro tamom kon
                        fclose(fptr);
                    }
                    else if(index1>index)
                    {
                        printf("index out of bonds!\n");
                        fclose(fptr);
                    }
                    else
                    {
                        int inds = index_in_str(str);
                        char str_final[MAX];
                        int i, j, k;
                        for(i = 0; i<inds; i++)
                        {
                            str_final[i] = str[i];
                        }
                        for(j = inds; j<(inds+strlen(text_to_insert)); j++)
                        {
                            str_final[j] = text_to_insert[j-inds];
                        }
                        for(k = (inds+strlen(text_to_insert)); str[k]!='\0'; k++)
                        {
                            str_final[k] = str[k-strlen(text_to_insert)];
                        }
                        str_final[k] = '\0';
                        fprintf(fptr, "%s", str_final);
                        fclose(fptr);
                    }
                }
        }
        else
        {
            printf("invalid command(--str)\n");
        }
    }
    }
    else
    {
        file_name[0] = c1;
        scanf("%s", file_name + 1);
        FILE *fptr = fopen(file_name, "r");

        if (fptr == NULL)
        {
            printf("there is no such file.\n");
            fclose(fptr);
        }
        else
        {
            char str[MAX_CMD];
            scanf("%s", str);
            getchar();
            if (!strcmp(str, "--str"))
            {
                char text_to_insert[MAX];
                char c = getchar();
                if(c == '\"')
                {
                    int b = 0;
                    char ch = getchar();
                    while(ch != '\"')
                    {
                        text_to_insert[b] = ch;
                        b++ ;
                        ch = getchar();
                    }
                    text_to_insert[b] = '\0';
                    char pos[MAX_CMD];
                    scanf("%s", pos);
                    if(!strcmp(pos, "--pos"))
                    {
                    int index1, line1 , index, line;
                    scanf("%d:%d", &line1, &index1);
                    char str[MAX];
                    fscanf(fptr, "%[^\0]", str);
                    fclose(fptr);
                    fptr = fopen(file_name, "w");
                    line = how_many_lines(str);
                    if(line1<=line)
                    {
                        index = how_many_index_in_line(str, line1);
                    }
                    if(line1>line)
                    {
                        printf("line out of bonds!\n");//haminja tabe ro tamom kon
                        fclose(fptr);
                    }
                    else if(index1>index)
                    {
                        printf("index out of bonds!\n");
                        fclose(fptr);
                    }
                    else
                    {
                        int inds = index_in_str(str);
                        char str_final[MAX];
                        int i, j, k;
                        for(i = 0; i<inds; i++)
                        {
                            str_final[i] = str[i];
                        }
                        for(j = inds; j<(inds+strlen(text_to_insert)); j++)
                        {
                            str_final[j] = text_to_insert[j-inds];
                        }
                        for(k = (inds+strlen(text_to_insert)); str[k]!='\0'; k++)
                        {
                            str_final[k] = str[k-strlen(text_to_insert)];
                        }
                        str_final[k] = '\0';
                        fprintf(fptr, "%s", str_final);
                        fclose(fptr);
                    }
                    }
                    else
                    {
                        printf("invalid command(--pos)\n");
                    }

                }
                else
                {
                    text_to_insert[0] = c;
                    scanf("%s", text_to_insert + 1);
                    char pos[MAX_CMD];
                    scanf("%s", pos);
                    if(!strcmp(pos, "--pos"))
                    {
                    int index1, line1 , index, line;
                    scanf("%d:%d", &line1, &index1);
                    char str[MAX];
                    printf("%d\n", line1);
                    fscanf(fptr, "%[^\0]", str);
                    fclose(fptr);
                    fptr = fopen(file_name, "w");
                    line = how_many_lines(str);printf("%d\n", index1);

                    if(line1<=line)
                    {
                        index = how_many_index_in_line(str, line1);
                    }
                    if(line1>line)
                    {
                        printf("line out of bonds!\n");//haminja tabe ro tamom kon
                        fclose(fptr);
                    }
                    else if(index1>index)
                    {
                        printf("index out of bonds!\n");
                        fclose(fptr);
                    }
                    else
                    {
                        printf("%s\n", str);
                        int inds = index_in_str(str);
                        printf("%dinds\n", inds);
                        char str_final[MAX];
                        int i, j, k;
                        for(i = 0; i<=inds; i++)
                        {
                            str_final[i] = str[i];
                        }
                        for(j = inds+1; j<(inds+1+strlen(text_to_insert)); j++)
                        {
                            str_final[j] = text_to_insert[j-inds];
                        }
                        for(k = (inds+1+strlen(text_to_insert)); str[k]!='\0'; k++)
                        {
                            str_final[k] = str[k-strlen(text_to_insert)];
                        }
                        str_final[k] = '\0';
                        printf("%s\n", str_final);
                        fprintf(fptr, "%s", str_final);
                        fclose(fptr);
                        printf("Success\n");
                    }
                    }
                    else
                    {
                        printf("invalid command(--pos)\n");
                    }
                }
        }
    }
    }
    }
    else
    {
        printf("invalid command(--file)\n");
    }
}

void cat()
{
        char file[MAX_CMD];
        scanf("%s", file);
        getchar();
        if (!strcmp(file, "--file"))
        {
            check = 1;
            char file_name[MAX];
            char c = getchar();
            if(c == '\"')
            {
                int a = 0;
                char ch;
                while(ch != '\"')
                {
                    file_name[a] = ch;
                    a++ ;
                    ch = getchar();
                }
                file_name[a] = '\0';
                FILE* fptr = fopen(file_name, "r");
                if(fptr == NULL)
                {
                    printf("file vogood nadare!\n");
                    fclose(fptr);
                }
                else
                {
                    char str[MAX];
                    fscanf(fptr, "%[^\0]s", str);
                    printf("\nContent of File is:\n\n");
                    printf("%s\n", str);
                    fclose(fptr);
                }
            }
            else
            {
                file_name[0] = c;
                scanf("%s", file_name + 1);
                FILE* fptr = fopen(file_name, "r");
                if(fptr == NULL)
                {
                    printf("file vogood nadare!\n");
                    fclose(fptr);
                }
                else
                {
                    char str[MAX];
                    fscanf(fptr, "%[^\0]s", str);
                    printf("\nContent of File is:\n\n");
                    printf("%s\n", str);
                    fclose(fptr);
                }
            }
        }
        else
        {
            printf("invalid command(--file)\n");
        }
}

int check_create(char user_cmd[])
{
        check = 1;
        for (int i = 0; i < 6; i++)
        {
            if (create_cmd[i] != user_cmd[i])
            {
                check = 0;
                break;
            }
        }
        return check;
}

int check_insertstr(char user_cmd[])
{
    check = 1;
    for (int i = 0; i < 9; i++)
    {
        if (insertstr_cmd[i] != user_cmd[i])
        {
            check = 0;
            break;
        }
    }
    return check;
}

int check_cat(char user_cmd[])
{
    check = 1;
    for (int i = 0; i < 3; i++)
    {
        if (cat_cmd[i] != user_cmd[i])
        {
            check = 0;
            break;
        }
    }
    return check;
}
    // convert \n to newline
void new_line(char user_cmd[])
{
    int i = 1;
    while (user_cmd[i] != '\0')
    {
        if ((user_cmd[i - 1] == '\\') && (user_cmd[i] == 'n'))
        {
            user_cmd[i - 1] == '\n';
            int j = i;
            while (user_cmd[j] != '\0')
            {
                user_cmd[j] = user_cmd[j + 1];
                j++;
            }
            break;
        }
        i++;
    }
}

int check_exit(char user_cmd[])
{
        check = 1;
        for (int i = 0; i < 4; i++)
        {
            if (exit_cmd[i] != user_cmd[i])
            {
                check = 0;
                break;
            }
        }
    return check;
}

void remove1()
{
    char file[MAX];
    scanf("%s", file);
    if (!check_file(file))
    {
        printf("invalid command!\n");
    }

    else
    {
        char file_name[MAX];
        scanf("%s", file_name);

        if (check_Address_or_name(file_name))
        {
            char file_path[MAX] = "C:\\Users\\PC\\Desktop\\root\\";
            scanf("%s", &file_path[25]);
            FILE *fptr = fopen(file_path, "w");

            if (fptr == NULL)
            {
                printf("there is no such file!\n");
            }

            else
            {
                char pos[MAX];
                scanf("%s", pos);
                if (check_pos(pos))
                {
                    int line, index;
                    char do_noghteh;
                    scanf("%d%c%d", line, do_noghteh, index);
                    char str_final[MAX];
                    fscanf(fptr, "%s", str_final);

                    if (line < how_many_lines(str_final))
                    {
                        int line_ma = 1, index_ma = 0, count = 0;

                        while (str_final[count] != '\0')
                        {
                            if (line_ma == line && index_ma == index)
                            {
                                break;
                            }

                            if (str_final[count] == '\n')
                            {
                                line_ma++;
                                index_ma = 0;
                            }

                            index_ma++;
                            count++;
                        }

                        char size1[MAX];
                        scanf("%s", size1);

                        if (check_size(size1))
                        {
                            int size;
                            scanf("%d", size);
                            char back_for[2];
                            scanf("%s", back_for);

                            if (b_or_f(back_for))
                            {
                                char str_final_last[MAX];

                                for (int i = 0; i < (count - size); i++)
                                {
                                    str_final_last[i] = str_final[i];
                                }

                                for (int i = (count - size); str_final[i] != '\0'; i++)
                                {
                                    str_final_last[i] = str_final[i + size];
                                }

                                fclose(fptr);
                                fopen(file_path, "w");
                                fprintf(fptr, "%s", str_final_last);
                                printf("success\n");
                            }
                        }
                    }
                }
            }
            fclose(fptr);
        }
    }
}

int check_remove(char user_cmd[])
{
    check = 1;

    for (int i = 0; i < 9; i++)
    {
        if (user_cmd[i] != remove_cmd[i])
        {
            check = 0;
            break;
        }
    }

    return check;
}

int check_file(char user_cmd[])
{
    check = 1;

    for (int i = 0; i < 6; i++)
    {
        if (user_cmd[i] != file_cmd[i])
        {
            check = 0;
            break;
        }
    }

    return check;
}

int check_Address_or_name(char file_name[])
{
    check = 1;
    for (int i = 0; file_name[i] != '\0'; i++)
    {
        if (file_name[i] == '/')
        {
            check = 0;
            break;
        }
    }

    return check; // if check == 0 ==> path ; else ==> name
}


int check_size(char user_cmd[])
{
    check = 1;
    for (int i = 0; i < 5; i++)
    {
        if (user_cmd[i] != size_cmd[i])
        {
            check = 0;
            break;
        }
    }

    return check;
}

int check_pos(char user_cmd[])
{
    check = 1;

    for (int i = 0; i < 5; i++)
    {
        if (user_cmd[i] != pos_cmd[i])
        {
            check = 0;
            break;
        }
    }

    return check;
}

int b_or_f(char user_cmd[])
{
    if (user_cmd[0] == '-' && user_cmd[1] == 'b')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void copy()
{
    char file[MAX_CMD];
    scanf("%s", file);
    if(!strcmp(file, "--file"))
    {
        char file_name[MAX];
        getchar();
        char dash = getchar();
        //printf("%c", dash);
        if(dash == '\"')
        {
            int a = 0;
            char c;
            while((c=getchar()) != '\"')
            {
                file_name[a] = c;
                a++ ;
            }
            //printf("%s", file_name);
            FILE* file_for_copy = fopen(file_name, "r");
            if(file_for_copy == NULL)
            {
                printf("there is no such a file\n");//haminja tabe ro tamom kon
                return -1;
            }
            else
            {
                char coppied_text[MAX];
                fscanf(file_for_copy, "%s", coppied_text);
                char coppied_file[MAX];
                fscanf(file_for_copy, "%s", coppied_file);
                int line_no, line_no1 = 1, start_position, position = 0;
                scanf("%d:%d", &line_no, &start_position);
                int ind = 0;
                while(coppied_file[ind]!='\0')
                {
                    if(line_no1 == line_no && position == start_position)
                    {
                        break;
                    }
                    if(coppied_file[ind] == '\n')
                    {
                        line_no1++ ;
                        position = 0;
                    }
                    if(coppied_file[ind+1] == '\0')
                    {
                        printf("line or position not found\n");//haminja tabe ro tamom kon
                        return -1;
                    }
                    position++ ;
                    ind++ ;
                }
                clipboard = fopen("copy.txt", "w");
                int size;
                scanf("%d", &size);
                char copy_text[size];
                char back[MAX];
                scanf("%s", back);
                if(!strcmp(back, "-b"))
                {
                    int a, b;
                    for(a = ind-size, b = 0; a<ind; a++, b++)
                    {
                        copy_text[b] = coppied_file[a];
                    }
                    copy_text[b] = '\0';
                    fprintf(clipboard, "%s", copy_text);
                    fclose(clipboard);//haminja tabe ro tamom kon
                    return 0;
                }
                else if(!strcmp(back, "-f"))
                {
                    int c, d;
                    for(c = ind, d = 0; c<(ind+size); c++, d++)
                    {
                        copy_text[d]= coppied_file[c];
                    }
                    copy_text[d] = '\0';
                    fprintf(clipboard, "%s", copy_text);
                    fclose(clipboard);//haminja tabe ro tamom kon
                    return 0;
                }
                else
                {
                    fclose(clipboard);
                    printf("invalid command(-*)\n");//haminja tabe ro tamom kon
                }
            }

        }
        else
        {
            file_name[0] = dash;
            scanf("%s", file_name+1);
            FILE* file_for_copy = fopen(file_name, "r");
            if(file_for_copy == NULL)
            {
                printf("there is no such a file\n");//haminja tabe ro tamom kon
            }
            else
            {
                char coppied_file[MAX];
                fscanf(file_for_copy, "%s", coppied_file);
                int line_no, line_no1 = 1, start_position, position = 0;
                scanf("%d:%d", &line_no, &start_position);
                int ind = 0;
                while(coppied_file[ind]!='\0')
                {
                    if(line_no1 == line_no && position == start_position)
                    {
                        break;
                    }
                    if(coppied_file[ind] == '\n')
                    {
                        line_no1++ ;
                        position = 0;
                    }
                    if(coppied_file[ind+1] == '\0')
                    {
                        printf("line or position not found\n");//haminja tabe ro tamom kon
                    }
                    position++ ;
                    ind++ ;
                }
                clipboard = fopen("copy.txt", "w");
                int size;
                scanf("%d", &size);
                char copy_text[size];
                char back[MAX];
                scanf("%s", back);
                if(!strcmp(back, "-b"))
                {
                    int a, b;
                    for(a = ind-size, b = 0; a<ind; a++, b++)
                    {
                        copy_text[b] = coppied_file[a];
                    }
                    copy_text[b] = '\0';
                    fprintf(clipboard, "%s", copy_text);
                    fclose(clipboard);//haminja tabe ro tamom kon
                }
                else if(!strcmp(back, "-f"))
                {
                    int c, d;
                    for(c = ind, d = 0; c<(ind+size); c++, d++)
                    {
                        copy_text[d]= coppied_file[c];
                    }
                    copy_text[d] = '\0';
                    fprintf(clipboard, "%s", copy_text);
                    fclose(clipboard);//haminja tabe ro tamom kon
                }
                else
                {
                    fclose(clipboard);
                    printf("invalid command(-*)\n");//haminja tabe ro tamom kon
                }
            }
        }
    }
    else
    {
        printf("invalid command\n");//haminja tabe ro tamom kon
    }

}

int length(char text[])
{
    int result = 0;
    for(int i = 0; text[i]!='\0'; i++)
    {
        result = i;
    }
    result++ ;
    return result;
}

void find_features(char feature[], char file_text[], char text_to_find[])
{
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, check = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    check = 1;
                                    printf("Substring found at index %d\n", i);
                                }
                            }
                            if(check)
                            {
                                break;
                            }
                            p1++ ;
                        }
                        if(flag == 0)
                        {
                            printf("substring not found!\n");//haminja tabe ro tamom kon
                        }
                        else
                        {
                        if(!strcmp(feature, "-byword"))
                        {
                            printf("substring found at word %d\n", word);
                            char cha2 = getchar();
                            if(cha2 == 32)
                            {
                                char feature2[MAX_CMD];
                                scanf("%s", feature2);
                                if(!strcmp(feature2, "-all"))
                                {
                                char *p1, *p2, *p3;
                                int i = 0, j = 0, flag = 0, check = 0, word = 1;
                                p1 = file_text;
                                p2 = text_to_find;
                                for(i = 0; i<strlen(file_text); i++)
                                {
                                    if(*p1 == *p2)
                                    {
                                        p3 = p1;
                                        for(j = 0; j<strlen(text_to_find); j++)
                                        {
                                            if(*p3 == *p2)
                                            {
                                                p3++;p2++;
                                            }
                                            else
                                                break;
                                        }
                                        p2 = text_to_find;
                                        if(j == strlen(text_to_find))
                                        {
                                            flag = 1;
                                            if(check == 1)
                                            {
                                            printf("Substring found at index %d\n", i);
                                            }
                                            check = 1;
                                        }
                                    }
                                    p1++ ;
                                }
                                }
                                else if(!strcmp(feature2, "-count"))
                                {
                                char *p1, *p2, *p3;
                                int i = 0, j = 0, flag = 0, count = 0, word = 1;
                                p1 = file_text;
                                p2 = text_to_find;
                                for(i = 0; i<strlen(file_text); i++)
                                {
                                    if(*p1 != 32 && *(p1+1) == 32)
                                    {
                                        word++ ;
                                    }
                                    if(*p1 == *p2)
                                    {
                                        p3 = p1;
                                        for(j = 0; j<strlen(text_to_find); j++)
                                        {
                                            if(*p3 == *p2)
                                            {
                                                p3++;p2++;
                                            }
                                            else
                                                break;
                                        }
                                        p2 = text_to_find;
                                        if(j == strlen(text_to_find))
                                        {
                                            flag = 1;
                                            count++ ;

                                        }
                                    }
                                    p1++ ;
                                }
                                printf("matn %d bar tekrar shode ast\n", count);
                                }
                                else if(!strcmp(feature2, "-at"))
                                {
                                int tekrar;
                                scanf("%d", &tekrar);
                                char *p1, *p2, *p3;
                                int i = 0, j = 0, flag = 0, count = 0, word = 1;
                                p1 = file_text;
                                p2 = text_to_find;
                                for(i = 0; i<strlen(file_text); i++)
                                {
                                    if(*p1 != 32 && *(p1+1) == 32)
                                    {
                                        word++ ;
                                    }
                                    if(*p1 == *p2)
                                    {
                                        p3 = p1;
                                        for(j = 0; j<strlen(text_to_find); j++)
                                        {
                                            if(*p3 == *p2)
                                            {
                                                p3++;p2++;
                                            }
                                            else
                                                break;
                                        }
                                        p2 = text_to_find;
                                        if(j == strlen(text_to_find))
                                        {
                                            flag = 1;
                                            count++ ;

                                        }
                                    }
                                    p1++ ;
                                }
                                if(count < tekrar)
                                {
                                    printf("-1\n");
                                }
                                }
                                else
                                {
                                    printf("invalid command(feature2)\n");
                                }
                            }
                        }
                        else if(!strcmp(feature, "-all"))
                        {
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, check = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    if(check == 1)
                                    {
                                    printf("Substring found at index %d\n", i);
                                    }
                                    check = 1;
                                }
                            }
                            p1++ ;
                        }
                            char cha2 = getchar();
                            if(cha2 == 32)
                            {
                                char feature2[MAX_CMD];
                                scanf("%s", feature2);
                                if(!strcmp(feature2, "-byword"))
                                {
                                    printf("substring found at word %d\n", word);
                                }
                                else if(!strcmp(feature2, "-count"))
                                {
                                char *p1, *p2, *p3;
                                int i = 0, j = 0, flag = 0, count = 0, word = 1;
                                p1 = file_text;
                                p2 = text_to_find;
                                for(i = 0; i<strlen(file_text); i++)
                                {
                                    if(*p1 != 32 && *(p1+1) == 32)
                                    {
                                        word++ ;
                                    }
                                    if(*p1 == *p2)
                                    {
                                        p3 = p1;
                                        for(j = 0; j<strlen(text_to_find); j++)
                                        {
                                            if(*p3 == *p2)
                                            {
                                                p3++;p2++;
                                            }
                                            else
                                                break;
                                        }
                                        p2 = text_to_find;
                                        if(j == strlen(text_to_find))
                                        {
                                            flag = 1;
                                            count++ ;

                                        }
                                    }
                                    p1++ ;
                                }
                                printf("matn %d bar tekrar shode ast\n", count);
                                }
                                else
                                {
                                    printf("invalid command(feature2)\n");
                                }
                            }
                        }
                        else if(!strcmp(feature, "-count"))
                        {
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, count = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    count++ ;

                                }
                            }
                            p1++ ;
                        }
                        printf("matn %d bar tekrar shode ast\n", count);
                            char cha2 = getchar();
                            if(cha2 == 32)
                            {
                                char feature2[MAX_CMD];
                                scanf("%s", feature2);
                                if(!strcmp(feature2, "-byword"))
                                {
                                    printf("substring found at word %d\n", word);
                                }
                                else if(!strcmp(feature2, "-all"))
                                {
                                char *p1, *p2, *p3;
                                int i = 0, j = 0, flag = 0, check = 0, word = 1;
                                p1 = file_text;
                                p2 = text_to_find;
                                for(i = 0; i<strlen(file_text); i++)
                                {
                                    if(*p1 == *p2)
                                    {
                                        p3 = p1;
                                        for(j = 0; j<strlen(text_to_find); j++)
                                        {
                                            if(*p3 == *p2)
                                            {
                                                p3++;p2++;
                                            }
                                            else
                                                break;
                                        }
                                        p2 = text_to_find;
                                        if(j == strlen(text_to_find))
                                        {
                                            flag = 1;
                                            if(check == 1)
                                            {
                                            printf("Substring found at index %d\n", i);
                                            }
                                            check = 1;
                                        }
                                    }
                                    p1++ ;
                                }
                                }
                                else if(!strcmp(feature2, "-at"))
                                {
                                int tekrar;
                                scanf("%d", &tekrar);
                                char *p1, *p2, *p3;
                                int i = 0, j = 0, flag = 0, count = 0, word = 1;
                                p1 = file_text;
                                p2 = text_to_find;
                                for(i = 0; i<strlen(file_text); i++)
                                {
                                    if(*p1 != 32 && *(p1+1) == 32)
                                    {
                                        word++ ;
                                    }
                                    if(*p1 == *p2)
                                    {
                                        p3 = p1;
                                        for(j = 0; j<strlen(text_to_find); j++)
                                        {
                                            if(*p3 == *p2)
                                            {
                                                p3++;p2++;
                                            }
                                            else
                                                break;
                                        }
                                        p2 = text_to_find;
                                        if(j == strlen(text_to_find))
                                        {
                                            flag = 1;
                                            count++ ;

                                        }
                                    }
                                    p1++ ;
                                }
                                if(count < tekrar)
                                {
                                    printf("-1\n");
                                }
                                }
                                else
                                {
                                    printf("invalid command(feature2)\n");
                                }
                            }
                        }
                        else if(!strcmp(feature, "-at"))
                        {
                        int tekrar;
                        scanf("%d", &tekrar);
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, count = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    count++ ;

                                }
                            }
                            p1++ ;
                        }
                        if(count < tekrar)
                        {
                            printf("-1\n");
                        }
                            char cha2 = getchar();
                            if(cha2 == 32)
                            {
                                char feature2[MAX_CMD];
                                scanf("%s", feature2);
                                if(!strcmp(feature2, "-byword"))
                                {
                                    printf("substring found at word %d\n", word);
                                }
                                else if(!strcmp(feature2, "-count"))
                                {
                                char *p1, *p2, *p3;
                                int i = 0, j = 0, flag = 0, count = 0, word = 1;
                                p1 = file_text;
                                p2 = text_to_find;
                                for(i = 0; i<strlen(file_text); i++)
                                {
                                    if(*p1 != 32 && *(p1+1) == 32)
                                    {
                                        word++ ;
                                    }
                                    if(*p1 == *p2)
                                    {
                                        p3 = p1;
                                        for(j = 0; j<strlen(text_to_find); j++)
                                        {
                                            if(*p3 == *p2)
                                            {
                                                p3++;p2++;
                                            }
                                            else
                                                break;
                                        }
                                        p2 = text_to_find;
                                        if(j == strlen(text_to_find))
                                        {
                                            flag = 1;
                                            count++ ;

                                        }
                                    }
                                    p1++ ;
                                }
                                printf("matn %d bar tekrar shode ast\n", count);
                                }
                                else
                                {
                                    printf("invalid command(feature2)\n");
                                }
                            }
                        }
                        else
                        {
                            printf("invalid command(feature)\n");//haminja tabe ro tamom kon
                        }
                        }
}

void find()
{
    char str[MAX_CMD];
    scanf("%s", str);
    if(!strcmp(str, "--str"))
    {
        char text_to_find[MAX];
        getchar();
        char dash = getchar();
        if(dash == '\"')
        {
            char c;
            int a = 0;
            while((c=getchar()) != '\"')
            {
                text_to_find[a] = c;
                a++ ;
            }
            text_to_find[a] = '\0';
            char file[MAX_CMD];
            scanf("%s", file);
            if(!strcmp(file, "--file"))
            {
                char file_name[MAX];
                getchar();
                char dash1 = getchar();
                if(dash1 == '\"')
                {
                    char ch;
                    int b = 0;
                    while((ch=getchar()) != '\"')
                    {
                        file_name[b] = ch;
                        b++ ;
                    }
                    file_name[b] = '\0';
                    FILE* fptr = fopen(file_name, "r");
                    if(fptr == NULL)
                    {
                        printf("there is no such a file!\n");
                    }
                    else
                    {
                        char file_text[MAX];
                        fscanf(fptr, "%[^\0]s", file_text);//hala boro matno peida kon
                        printf("%s\n", file_text);
                        printf("%d\n", strlen(file_text));
                        char cha = getchar();
                        if(cha == 32)
                        {
                        char feature[MAX_CMD];
                        scanf("%s", feature);
                        find_features(feature, file_text, text_to_find);
                        }
                        if(cha == 10)
                        {
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, check = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    check = 1;
                                    printf("Substring found at index %d\n", i);
                                }
                            }
                            if(check)
                            {
                                break;
                            }
                            p1++ ;
                        }
                        if(flag == 0)
                        {
                            printf("substring not found!\n");
                        }
                        }

                }
                }
                else
                {
                    file_name[0] = dash1;
                    scanf("%s", file_name+1);
                    FILE* fptr = fopen(file_name, "r");
                    if(fptr == NULL)
                    {
                        printf("there is no such a file!\n");
                    }
                    else
                    {
                        char file_text[MAX];
                        fscanf(fptr, "%[^\0]s", file_text);//hala boro matno peida kon
                        printf("%s\n", file_text);
                        printf("%d\n", strlen(file_text));
                        char cha = getchar();
                        if(cha == 32)
                        {
                        char feature[MAX_CMD];
                        scanf("%s", feature);
                        find_features(feature, file_text, text_to_find);
                        }
                        if(cha == 10)
                        {
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, check = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    check = 1;
                                    printf("Substring found at index %d\n", i);
                                }
                            }
                            if(check)
                            {
                                break;
                            }
                            p1++ ;
                        }
                        if(flag == 0)
                        {
                            printf("substring not found!\n");
                        }
                        }
                    }
            }
            }
            else
            {
                printf("invalid command(--file)\n");//haminja tabe ro tamom kon
            }

        }
        else
        {
            text_to_find[0] = dash;
            scanf("%s", text_to_find+1);
            char file[MAX_CMD];
            scanf("%s", file);
            if(!strcmp(file, "--file"))
            {
                char file_name[MAX];
                getchar();
                char dash1 = getchar();
                if(dash1 == '\"')
                {
                    char ch;
                    int b = 0;
                    while((ch=getchar()) != '\"')
                    {
                        file_name[b] = ch;
                        b++ ;
                    }
                    file_name[b] = '\0';
                    FILE* fptr = fopen(file_name, "r");
                    if(fptr == NULL)
                    {
                        printf("there is no such a file!\n");
                    }
                    else
                    {
                        char file_text[MAX];
                        fscanf(fptr, "%[^\0]s", file_text);//hala boro matno peida kon
                        printf("%s\n", file_text);
                        printf("%d\n", strlen(file_text));
                        char cha = getchar();
                        if(cha == 32)
                        {
                        char feature[MAX_CMD];
                        scanf("%s", feature);
                        find_features(feature, file_text, text_to_find);
                        }
                        if(cha == 10)
                        {
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, check = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    check = 1;
                                    printf("Substring found at index %d\n", i);
                                }
                            }
                            if(check)
                            {
                                break;
                            }
                            p1++ ;
                        }
                        if(flag == 0)
                        {
                            printf("substring not found!\n");
                        }
                        }
                    }
                }
                else
                {
                    file_name[0] = dash1;
                    scanf("%s", file_name+1);
                    FILE* fptr = fopen(file_name, "r");
                    if(fptr == NULL)
                    {
                        printf("there is no such a file!\n");
                    }
                    else
                    {
                        char file_text[MAX];
                        fscanf(fptr, "%[^\0]s", file_text);//hala boro matno peida kon
                        printf("%s\n", file_text);
                        printf("%d\n", strlen(file_text));
                        char cha = getchar();
                        if(cha == 32)
                        {
                        char feature[MAX_CMD];
                        scanf("%s", feature);
                        find_features(feature, file_text, text_to_find);
                        }
                        if(cha == 10)
                        {
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, check = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    check = 1;
                                    printf("Substring found at index %d\n", i);
                                }
                            }
                            if(check)
                            {
                                break;
                            }
                            p1++ ;
                        }
                        if(flag == 0)
                        {
                            printf("substring not found!\n");
                        }
                        }
                    }
                }
            }
            else
            {
                printf("invalid command(--file)\n");//haminja tabe ro tamom kon
            }
        }
    }
    else
    {
        printf("invalid command!\n");//haminja tabe ro tamom kon
    }
}


/*void replace()
{
    char str[MAX_CMD];
    scanf("%s", str);
    if(!strcmp(str, "--str"))
    {
        char text_to_find[MAX];
        char text_to_replace[MAX];
        getchar();
        char dash = getchar();
        if(dash == '\"')
        {
            char c;
            int a = 0;
            while((c=getchar()) != '\"')
            {
                text_to_find[a] = c;
                a++ ;
            }
            text_to_find[a] = '\0';
            scanf("%s", text_to_replace);
            char file[MAX_CMD];
            scanf("%s", file);
            if(!strcmp(file, "--file"))
            {
                char file_name[MAX];
                getchar();
                char dash1 = getchar();
                if(dash1 == '\"')
                {
                    char ch;
                    int b = 0;
                    while((ch=getchar()) != '\"')
                    {
                        file_name[b] = ch;
                        b++ ;
                    }
                    file_name[b] = '\0';
                    FILE* fptr = fopen(file_name, "r");
                    if(fptr == NULL)
                    {
                        printf("there is no such a file!\n");
                    }
                    else
                    {
                        char file_text[MAX];
                        fscanf(fptr, "%[^\0]", file_text);//hala boro matno peida kon
                        printf("%s\n", file_text);
                        printf("%d\n", strlen(file_text));
                        char cha = getchar();
                        if(cha == 32)
                        {
                        char feature[MAX_CMD];
                        scanf("%s", feature);
                        replace_features(feature, file_text, text_to_find);
                        }
                        if(cha == 10)
                        {
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, check = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    check = 1;
                                    printf("Substring found at index %d\n", i);
                                }
                            }
                            if(check)
                            {
                                break;
                            }
                            p1++ ;
                        }
                        if(flag == 0)
                        {
                            printf("substring not found!\n");
                        }
                        }

                }
                }
                else
                {
                    file_name[0] = dash1;
                    scanf("%s", file_name+1);
                    FILE* fptr = fopen(file_name, "r");
                    if(fptr == NULL)
                    {
                        printf("there is no such a file!\n");
                    }
                    else
                    {
                        char file_text[MAX];
                        fscanf(fptr, "%[^\0]s", file_text);//hala boro matno peida kon
                        printf("%s\n", file_text);
                        printf("%d\n", strlen(file_text));
                        char cha = getchar();
                        if(cha == 32)
                        {
                        char feature[MAX_CMD];
                        scanf("%s", feature);
                        replace_features(feature, file_text, text_to_find);
                        }
                        if(cha == 10)
                        {
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, check = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    check = 1;
                                    printf("Substring found at index %d\n", i);
                                }
                            }
                            if(check)
                            {
                                break;
                            }
                            p1++ ;
                        }
                        if(flag == 0)
                        {
                            printf("substring not found!\n");
                        }
                        }
                    }
            }
            }
            else
            {
                printf("invalid command(--file)\n");//haminja tabe ro tamom kon
            }

        }
        else
        {
            text_to_find[0] = dash;
            scanf("%s", text_to_find+1);
            scanf("%s", text_to_replace);
            char file[MAX_CMD];
            scanf("%s", file);
            if(!strcmp(file, "--file"))
            {
                char file_name[MAX];
                getchar();
                char dash1 = getchar();
                if(dash1 == '\"')
                {
                    char ch;
                    int b = 0;
                    while((ch=getchar()) != '\"')
                    {
                        file_name[b] = ch;
                        b++ ;
                    }
                    file_name[b] = '\0';
                    FILE* fptr = fopen(file_name, "r");
                    if(fptr == NULL)
                    {
                        printf("there is no such a file!\n");
                    }
                    else
                    {
                        char file_text[MAX];
                        fscanf(fptr, "%[^\0]s", file_text);//hala boro matno peida kon
                        printf("%s\n", file_text);
                        printf("%d\n", strlen(file_text));
                        char cha = getchar();
                        if(cha == 32)
                        {
                        char feature[MAX_CMD];
                        scanf("%s", feature);
                        replace_features(feature, file_text, text_to_find);
                        }
                        if(cha == 10)
                        {
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, check = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    check = 1;
                                    printf("Substring found at index %d\n", i);
                                }
                            }
                            if(check)
                            {
                                break;
                            }
                            p1++ ;
                        }
                        if(flag == 0)
                        {
                            printf("substring not found!\n");
                        }
                        }
                    }
                }
                else
                {
                    file_name[0] = dash1;
                    scanf("%s", file_name+1);
                    FILE* fptr = fopen(file_name, "r");
                    if(fptr == NULL)
                    {
                        printf("there is no such a file!\n");
                    }
                    else
                    {
                        char file_text[MAX];
                        fscanf(fptr, "%[^\0]s", file_text);//hala boro matno peida kon
                        printf("%s\n", file_text);
                        printf("%d\n", strlen(file_text));
                        char cha = getchar();
                        if(cha == 32)
                        {
                        char feature[MAX_CMD];
                        scanf("%s", feature);
                        replace_features(feature, file_text, text_to_find);
                        }
                        if(cha == 10)
                        {
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, check = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    check = 1;
                                    printf("Substring found at index %d\n", i);
                                }
                            }
                            if(check)
                            {
                                break;
                            }
                            p1++ ;
                        }
                        if(flag == 0)
                        {
                            printf("substring not found!\n");
                        }
                        }
                    }
                }
            }
            else
            {
                printf("invalid command(--file)\n");//haminja tabe ro tamom kon
            }
        }
    }
    else
    {
        printf("invalid command!\n");//haminja tabe ro tamom kon
    }
}*/

void grep()
{
    char str[MAX_CMD];
    scanf("%s", str);
    getchar();
    if(!strcmp(str, "--str"))
    {
        char text_to_find[MAX];
        getchar();
        char ch = getchar();
        printf("%c\n", ch);
        int a = 0;
        while(ch!='\"')
        {
            text_to_find[a] = ch;
            a++;
            ch = getchar();
        }
        str[a] = '\0';
        char files[MAX_CMD];
        scanf("%s", files);printf("%s\n", text_to_find);
        if(!strcmp(files, "--files"))
        {
            char file_name[MAX];
            scanf("%s", file_name);
            char c1 = getchar();
            FILE* fptr = fopen(file_name, "r");
            if(fptr == NULL)
            {
                printf("there is no such a file\n");
            }
            else
            {
                char file_text[MAX];
                fscanf(fptr, "%s", file_text);
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, check = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    check = 1;
                                    printf("%s: ", file_name);
                                    for(int k = i;file_text[k]!=text_to_find[strlen(text_to_find)-1];k++)
                                    {
                                        printf("%c", file_text[k]);
                                    }
                                    printf("\n");
                                }
                            }
                            p1++ ;
                        }
                        if(flag == 0)
                        {
                            printf("pattern not found!\n");//haminja tabe ro tamom kon
                        }
                        if(c1 == 32)
                        {
                            char file_name2[MAX];
                            scanf("%s", file_name2);
                            FILE* fptr2 = fopen(file_name2, "r");
                            if(fptr2 == NULL)
                            {
                                printf("there is no such a file(file2)\n");
                            }
                            else
                            {
                        char file_text[MAX];
                        fscanf(fptr, "%s", file_text);
                        char *p1, *p2, *p3;
                        int i = 0, j = 0, flag = 0, check = 0, word = 1;
                        p1 = file_text;
                        p2 = text_to_find;
                        for(i = 0; i<strlen(file_text); i++)
                        {
                            if(*p1 != 32 && *(p1+1) == 32)
                            {
                                word++ ;
                            }
                            if(*p1 == *p2)
                            {
                                p3 = p1;
                                for(j = 0; j<strlen(text_to_find); j++)
                                {
                                    if(*p3 == *p2)
                                    {
                                        p3++;p2++;
                                    }
                                    else
                                        break;
                                }
                                p2 = text_to_find;
                                if(j == strlen(text_to_find))
                                {
                                    flag = 1;
                                    check = 1;
                                    printf("%s: ", file_name);
                                    for(int k = i;file_text[k]!=text_to_find[strlen(text_to_find)-1];k++)
                                    {
                                        printf("%c", file_text[k]);
                                    }
                                    printf("\n");
                                }
                            }
                            p1++ ;
                        }
                        if(flag == 0)
                        {
                            printf("pattern not found!\n");//haminja tabe ro tamom kon
                        }
                            }
                        }
            }
        }
        else
        {
            printf("invalid command(--files)\n");
        }
    }
    else
    {
        printf("invalid command(--str)\n");
    }
}

/*void compare()
{
    char file_name1[MAX], file_name2[MAX];
    FILE* fptr1 = fopen(file_name1, "r");
    FILE* fptr2 = fopen(file_name2, "r");
    int start1, start2;
    if(fptr1==NULL || fptr2==NULL)
    {
        printf("there is no such a file\n");
    }
    else
    {
        char file_text1[MAX], file_text2[MAX];
        fscanf(fptr1, "%s", file_text1);
        fscanf(fptr2, "%s", file_text2);
        int line1 = 1, line2 = 1;
        int line11, line21;
        line11 = how_many_lines(file_text1);
        line21 = how_many_lines(file_text2);
        for(int i = 0; i<=(min(line11, line21)); i++)
        {
            if(file_text1[i]!=file_text2[i] && (line1 == line2))
            {
                printf("====#line number:%d====", line);
                for(int k = start1; file_text1[k]!=10; k++)
                {
                    printf("%c", file_text1[k]);
                }
                printf("\n");
                for(int l = start2; file_text2[l]!=10; l++)
                {
                    printf("%c", file_text2[l]);
                }
                printf("\n");
                
                
            }
            if(file_text1[i]==10)
            {
                start1 = i;
                line1++ ;
            }
            if(file_text2[i]==10)
            {
                start2 = i;
                line2++ ;
            }
        }
    }
}*/

int main()
{
    char command[MAX_CMD];

    while(1)
    {
        fflush(stdin);
        scanf("%s", command);
        if(!strcmp(command, "createfile"))
        {
            createfile();
            continue;
        }
        else if(!strcmp(command, "insertstr"))
        {
            insert();
            continue;
        }
        else if(!strcmp(command, "cat"))
        {
            cat();
            continue;
        }
        else if(!strcmp(command, "removestr"))
        {
            remove1();
            continue;
        }
        else if(!strcmp(command, "copystr"))
        {
            copy();
            continue;
        }
        else if(!strcmp(command, "find"))
        {
            find();
            continue;
        }
        else if(!strcmp(command, "grep"))
        {
            grep();
            continue;
        }
        else if(!strcmp(command, "exit"))
        {
            break;
        }
        else
        {
            printf("invalid command!\n");
        }
    }

    return 0;
}
