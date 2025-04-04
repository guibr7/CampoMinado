
// cores e formato de texto
#define RESET "\x1b[0m"     
#define ANSI_RESET            "\x1b[0m"  // desativa os efeitos anteriores
#define ANSI_BOLD             "\x1b[1m"  // coloca o texto em negrito
#define ANSI_COLOR_BLACK      "\x1b[30m"
#define ANSI_COLOR_RED        "\x1b[31m"
#define ANSI_COLOR_GREEN      "\x1b[32m"
#define ANSI_COLOR_YELLOW     "\x1b[33m"
#define ANSI_COLOR_BLUE       "\x1b[34m"
#define ANSI_COLOR_MAGENTA    "\x1b[35m"
#define ANSI_COLOR_CYAN       "\x1b[36m"
#define ANSI_COLOR_WHITE      "\x1b[37m"
#define ANSI_BG_COLOR_BLACK   "\x1b[40m"
#define ANSI_BG_COLOR_RED     "\x1b[41m"
#define ANSI_BG_COLOR_GREEN   "\x1b[42m"
#define ANSI_BG_COLOR_YELLOW  "\x1b[43m"
#define ANSI_BG_COLOR_BLUE    "\x1b[44m"
#define ANSI_BG_COLOR_MAGENTA "\x1b[45m"
#define ANSI_BG_COLOR_CYAN    "\x1b[46m"
#define ANSI_BG_COLOR_WHITE   "\x1b[47m"


// macros para facilitar o uso
#define BOLD(string)       ANSI_BOLD             string ANSI_RESET
#define BLACK(string)      ANSI_COLOR_BLACK      string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define RED(string)        ANSI_COLOR_RED        string ANSI_RESET
#define GREEN(string)      ANSI_COLOR_GREEN      string ANSI_RESET
#define YELLOW(string)     ANSI_COLOR_YELLOW     string ANSI_RESET
#define BLUE(string)       ANSI_COLOR_BLUE       string ANSI_RESET
#define MAGENTA(string)    ANSI_COLOR_MAGENTA    string ANSI_RESET
#define CYAN(string)       ANSI_COLOR_CYAN       string ANSI_RESET

#define BG_BLACK(string)   ANSI_BG_COLOR_BLACK   string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_RED(string)     ANSI_BG_COLOR_RED     string ANSI_RESET
#define BG_GREEN(string)   ANSI_BG_COLOR_GREEN   string ANSI_RESET
#define BG_YELLOW(string)  ANSI_BG_COLOR_YELLOW  string ANSI_RESET
#define BG_BLUE(string)    ANSI_BG_COLOR_BLUE    string ANSI_RESET
#define BG_MAGENTA(string) ANSI_BG_COLOR_MAGENTA string ANSI_RESET
#define BG_CYAN(string)    ANSI_BG_COLOR_CYAN    string ANSI_RESET
#define WHITE(string)      ANSI_COLOR_WHITE      string ANSI_RESET

#define BG_DARK_GRAY "\x1b[48;5;235m"  // Cinza escuro
#define BG_LIGHT_GRAY "\x1b[48;5;245m" // Cinza claro
#define BG_YELLOW_BRIGHT "\x1B[103m"
#define YELLOW_BRIGHT "\x1B[1;33m"
#define ANSI_COLOR_WHITE_BRIGHT  "\x1b[97m"
#define ANSI_COLOR_BLACK_BRIGHT  "\x1b[90m"
#define BG_WHITE "\x1B[47m"  // Fundo branco
#define BG_GRAY "\x1B[47m"  // Fundo cinza



// caracteres uteis para tabelas
#define TAB_HOR "\u2501" // ━ (horizontal)
#define TAB_VER "\u2503" // ┃ (vertical)
#define TAB_TL  "\u250F" // ┏ (top-left)
#define TAB_ML  "\u2523" // ┣ (middle-left)
#define TAB_BL  "\u2517" // ┗ (bottom-left)
#define TAB_TJ  "\u2533" // ┳ (top-join)
#define TAB_MJ  "\u254B" // ╋ (middle-join)
#define TAB_BJ  "\u253B" // ┻ (bottom-join)
#define TAB_TR  "\u2513" // ┓ (top-right)
#define TAB_MR  "\u252B" // ┫ (middle-right)
#define TAB_BR  "\u251B" // ┛ (bottom-right)
 



#define BG_CINZA_ESCURO "\x1b[48;5;235m"  // Cinza escuro
#define BG_CINZA_CLARO "\x1b[48;5;245m" // Cinza claro

#define ANSI_COLOR_WHITE_BRIGHT  "\x1b[97m"
#define ANSI_COLOR_BLACK_BRIGHT  "\x1b[90m"

// Fundo Branco Brilhante e Preto Brilhante
#define ANSI_BG_WHITE_BRIGHT     "\x1b[107m"
#define ANSI_BG_BLACK_BRIGHT     "\x1b[100m"

// Negrito
#define ANSI_BOLD                "\x1b[1m"

// Macros para facilitar uso com strings
#define BLACK_BRIGHT(string)  ANSI_COLOR_BLACK_BRIGHT string ANSI_RESET
#define WHITE_BRIGHT(string)  ANSI_COLOR_WHITE_BRIGHT string ANSI_RESET
#define BG_BLACK_BRIGHT(string) ANSI_BG_BLACK_BRIGHT string ANSI_RESET
#define BG_WHITE_BRIGHT(string) ANSI_BG_WHITE_BRIGHT string ANSI_RESET