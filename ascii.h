void toAsciiArt(char texto[50])
{
    int bandera = 0;
    while(bandera < 4)
    {
        for(int i = 0; texto[i] != 0; i++)
        {
            if(texto[i] == 'a' || texto[i] == 'A')
            {
                if(bandera == 0) { printf("     "); }
                else if(bandera == 1) { printf("  /\\ "); }
                else if(bandera == 2) { printf(" /~~\\"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'b' || texto[i] == 'B')
            {
                if(bandera == 0) { printf("  __ "); }
                else if(bandera == 1) { printf(" |__)"); }
                else if(bandera == 2) { printf(" |__)"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'c' || texto[i] == 'C')
            {
                if(bandera == 0) { printf("  __ "); }
                else if(bandera == 1) { printf(" /  `"); }
                else if(bandera == 2) { printf(" \\__,"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'd' || texto[i] == 'D')
            {
                if(bandera == 0) { printf("  __ "); }
                else if(bandera == 1) { printf(" |  \\"); }
                else if(bandera == 2) { printf(" |__/"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'e' || texto[i] == 'E')
            {
                if(bandera == 0) { printf("  ___"); }
                else if(bandera == 1) { printf(" |__ "); }
                else if(bandera == 2) { printf(" |___"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'f' || texto[i] == 'F')
            {
                if(bandera == 0) { printf("  ___"); }
                else if(bandera == 1) { printf(" |__ "); }
                else if(bandera == 2) { printf(" |   "); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'g' || texto[i] == 'G')
            {
                if(bandera == 0) { printf("  __ "); }
                else if(bandera == 1) { printf(" / _`"); }
                else if(bandera == 2) { printf(" \\__/"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'h' || texto[i] == 'H')
            {
                if(bandera == 0) { printf("     "); }
                else if(bandera == 1) { printf(" |__|"); }
                else if(bandera == 2) { printf(" |  |"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'i' || texto[i] == 'I')
            {
                if(bandera == 0) { printf("  "); }
                else if(bandera == 1) { printf(" |"); }
                else if(bandera == 2) { printf(" |"); }
                else if(bandera == 3) { printf("  "); }
            }
            else if(texto[i] == 'j' || texto[i] == 'J')
            {
                if(bandera == 0) { printf("     "); }
                else if(bandera == 1) { printf("    |"); }
                else if(bandera == 2) { printf(" \\__/"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'k' || texto[i] == 'K')
            {
                if(bandera == 0) { printf("     "); }
                else if(bandera == 1) { printf(" |__/"); }
                else if(bandera == 2) { printf(" |  \\"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'l' || texto[i] == 'L')
            {
                if(bandera == 0) { printf("     "); }
                else if(bandera == 1) { printf(" |   "); }
                else if(bandera == 2) { printf(" |___"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'm' || texto[i] == 'M')
            {
                if(bandera == 0) { printf("     "); }
                else if(bandera == 1) { printf(" |\\/|"); }
                else if(bandera == 2) { printf(" |  |"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'n' || texto[i] == 'N')
            {
                if(bandera == 0) { printf("     "); }
                else if(bandera == 1) { printf(" |\\ |"); }
                else if(bandera == 2) { printf(" | \\|"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'o' || texto[i] == 'O')
            {
                if(bandera == 0) { printf("  __ "); }
                else if(bandera == 1) { printf(" /  \\"); }
                else if(bandera == 2) { printf(" \\__/"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'p' || texto[i] == 'P')
            {
                if(bandera == 0) { printf("  __ "); }
                else if(bandera == 1) { printf(" |__)"); }
                else if(bandera == 2) { printf(" |   "); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'q' || texto[i] == 'Q')
            {
                if(bandera == 0) { printf("  __ "); }
                else if(bandera == 1) { printf(" /  \\"); }
                else if(bandera == 2) { printf(" \\__X"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'r' || texto[i] == 'R')
            {
                if(bandera == 0) { printf("  __ "); }
                else if(bandera == 1) { printf(" |__)"); }
                else if(bandera == 2) { printf(" |  \\"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 's' || texto[i] == 'S')
            {
                if(bandera == 0) { printf("  __ "); }
                else if(bandera == 1) { printf(" /__`"); }
                else if(bandera == 2) { printf(" .__/"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 't' || texto[i] == 'T')
            {
                if(bandera == 0) { printf(" ___"); }
                else if(bandera == 1) { printf("  | "); }
                else if(bandera == 2) { printf("  | "); }
                else if(bandera == 3) { printf("    "); }
            }
            else if(texto[i] == 'u' || texto[i] == 'U')
            {
                if(bandera == 0) { printf("     "); }
                else if(bandera == 1) { printf(" |  |"); }
                else if(bandera == 2) { printf(" \\__/"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'v' || texto[i] == 'V')
            {
                if(bandera == 0) { printf("     "); }
                else if(bandera == 1) { printf(" \\  /"); }
                else if(bandera == 2) { printf("  \\/ "); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'w' || texto[i] == 'W')
            {
                if(bandera == 0) { printf("     "); }
                else if(bandera == 1) { printf(" |  |"); }
                else if(bandera == 2) { printf(" |/\\|"); }
                else if(bandera == 3) { printf("     "); }
            }
            else if(texto[i] == 'x' || texto[i] == 'X')
            {
                if(bandera == 0) { printf("    "); }
                else if(bandera == 1) { printf(" \\_/"); }
                else if(bandera == 2) { printf(" / \\"); }
                else if(bandera == 3) { printf("    "); }
            }
            else if(texto[i] == 'y' || texto[i] == 'Y')
            {
                if(bandera == 0) { printf("    "); }
                else if(bandera == 1) { printf(" \\ /"); }
                else if(bandera == 2) { printf("  | "); }
                else if(bandera == 3) { printf("    "); }
            }
            else if(texto[i] == 'z' || texto[i] == 'Z')
            {
                if(bandera == 0) { printf(" __"); }
                else if(bandera == 1) { printf("  /"); }
                else if(bandera == 2) { printf(" /_"); }
                else if(bandera == 3) { printf("   "); }
            }
        }
    printf("\n");
    bandera++;
    }
}
