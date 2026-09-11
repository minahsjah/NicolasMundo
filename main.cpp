#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>

static void *xfb = NULL;
static GXRModeObj *rmode = NULL;

int main(int argc, char **argv) {
    // Inicializa o sistema de vídeo do Wii
    VIDEO_Init();
    
    // Obtém o modo de vídeo correto (PAL/NTSC)
    rmode = VIDEO_GetPreferredMode(NULL);
    xfb = MEM_K0_TO_K1(SYS_AllocateFramebuffer(rmode));
    
    VIDEO_Configure(rmode);
    VIDEO_SetNextFramebuffer(xfb);
    VIDEO_SetBlack(FALSE);
    VIDEO_Flush();
    VIDEO_WaitVSync();

    // Inicializa o console de texto na tela
    console_init(xfb, 20, 20, rmode->fbWidth, rmode->xfbHeight, rmode->fbWidth * VI_DISPLAY_PIXELS_PER_BYTE);

    // Mensagens que vão aparecer no seu Dolphin Mobile ao abrir
    printf("\n\n\n");
    printf("=========================================\n");
    printf("     NICOLASMUNDO: CLUB PENGUIN REMAKE   \n");
    printf("=========================================\n");
    printf(" Coder: minahsjah\n");
    printf(" Versao: 1.0.0 (Wii DOL Homebrew Real)\n\n");
    printf(" Sistema carregado com sucesso no Dolphin!\n");
    printf(" Pressione o botao HOME no Wiimote para sair.\n");

    while(1) {
        VIDEO_WaitVSync();
        
        // Verifica os botões do controle do Wii
        WPAD_ScanPads();
        u32 pressed = WPAD_ButtonsDown(0);
        
        // Se pressionar HOME, o jogo fecha com segurança
        if (pressed & WPAD_BUTTON_HOME) {
            exit(0);
        }
    }

    return 0;
}

