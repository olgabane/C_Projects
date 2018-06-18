//Function to remove characters from string
void removeString(char string[], int index, int remove)
{
    int i = 0;
    do
        {
            if(i < index || i >= index+remove)
                {
                    printf("%c", string[i]);
                }
            i++;
        }
    while(string[i] != '\0');

}

int main (void)
{
    char string[] = {"the wrong son"};
    removeString (string, 4, 6);
    printf("\n");
    return 0;
}
