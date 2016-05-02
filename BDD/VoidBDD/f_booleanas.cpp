
char AND(char V1, char V2)
{
    return ((V1-48)&(V2-48))+48;
}
char OU(char V1, char V2)
{
    return ((V1-48)|(V2-48))+48;
}
char Negar(char V)
{
    return (1-(V-48))+48;
}
char Implica(char V1, char V2)
{
    return OU(Negar(V1),V2);
}
char  equivale(char V1, char V2)
{
    return AND(Implica(V1,V2),Implica(V2,V1));
}
char OU_exclusivo(char V1, char V2)
{
    return OU(AND(Negar(V1),V2),AND(Negar(V2),V1));

}
