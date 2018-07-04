#ifndef ___CGI_H___
#define ___CGI_H___

/**
@file cgi.h
\brief Macros úteis para gerar CGIs
*/

#include <stdio.h>

/**
* Caminho para as imagens
*/
#define IMAGE_PATH "http://localhost/images/"

/**
\brief Macro para começar o html
*/
#define COMECAR_HTML printf("Content-Type: text/html\n\n<html>\n")

/**
\brief Macro para defenir a cor de fundo da pagina do jogo
*/
#define BACKGROUNDCLR(COLOR) printf("<body bgcolor=%s>",COLOR)

/**
\brief Macro para abrir um svg
@param tamx O comprimento do svg
@param tamy A altura do svg
*/
#define ABRIR_SVG(tamx, tamy) printf("<svg width=%d height=%d>\n", tamx, tamy)
/**
\brief Macro para fechar um svg
*/
#define FECHAR_SVG printf("</svg>\n")

/**
\brief Macro para criar uma imagem com limitações sendo mais aplicada para a disposição de grelhas
@param X A coordenada X a partir do canto superior esquerdo
@param Y A coordenada Y a partir do canto superior esquerdo
@param ESCALA A escala da imagem
@param FICHEIRO O caminho para o link do ficheiro
*/
#define IMAGEM(X, Y, ESCALA, FICHEIRO) printf("<image x=%d y=%d width=%d height=%d xlink:href=%s%s />\n", \
											  ESCALA *X, ESCALA *Y, ESCALA, ESCALA, IMAGE_PATH, FICHEIRO)
/**
\brief Macro para criar uma imagem apenas com a limitação da posição relativa ao tamanho
@param X A coordenada X a partir do canto superior esquerdo
@param Y A coordenada Y a partir do canto superior esquerdo
@param ESCALAX A escala da imagem em x
@param ESCALAY A escala da imagem em y
@param FICHEIRO O caminho para o link do ficheiro
*/
#define IMAGEMTAM(X, Y, ESCALAX, ESCALAY, FICHEIRO) printf("<image x=%d y=%d width=%d height=%d xlink:href=%s%s />\n", \
											  ESCALAX *X, ESCALAY *Y, ESCALAX, ESCALAY, IMAGE_PATH, FICHEIRO)
/**
\brief Macro para criar uma imagem livre em qualquer posição com qualquer tamanho
@param X A coordenada X a partir do canto superior esquerdo
@param Y A coordenada Y a partir do canto superior esquerdo
@param ESCALAX A escala da imagem em x
@param ESCALAY A escala da imagem em y
@param FICHEIRO O caminho para o link do ficheiro
*/
#define IMAGEMTAMFREE(X, Y, ESCALAX, ESCALAY, FICHEIRO) printf("<image x=%d y=%d width=%d height=%d xlink:href=%s%s />\n", \
											  X, Y, ESCALAX, ESCALAY, IMAGE_PATH, FICHEIRO)

/**
\brief Macro para escrever texto

@param TAM Tamanho da fonte
@param X A coordenada X do canto superior esquerdo
@param Y A coordenada Y do canto inferior direito
@param TEXT Texto que se pretende escrever
*/
#define TEXTO(TAM, X, Y, TEXT) printf("<text font-size=%d x=%d y=%d>%s</text>\n", TAM, X, Y, TEXT)

/**
\brief Macro para criar um quadrado
@param X A coordenada X do canto superior esquerdo
@param Y A coordenada Y do canto superior esquerdo
@param ESCALA A escala do quadrado
@param COR A cor de preenchimento do quadrado
*/
#define QUADRADO(X, Y, ESCALA, COR) printf("<rect x=%d y=%d width=%d height=%d fill=%s />\n", \
										   ESCALA *X, ESCALA *Y, ESCALA, ESCALA, COR)

/**
\brief Macro para abrir um link
@param link O caminho para o link
*/
#define ABRIR_LINK(link) printf("<a xlink:href=%s>\n", link)

/**
\brief Macro para fechar o link
*/
#define FECHAR_LINK printf("</a>\n")

/**
 * \brief Macro para fechar o html
*/
#define FECHAR_HTML printf("</html>\n")

/**
 * \brief Macro para começar um form
*/
#define START_FORM printf("<form action=%s>\n", "http://localhost/cgi-bin/GandaGalo?")

/**
 * \brief Macro para a caixa de texto do form
 * 
 * @param NAME Texto a aparecer no form
 * @param INPUT Nome do input que se vai obter
 * @param SIZE Tamanho da caixa de texto
*/
#define FORM_TEXT(NAME, INPUT, SIZE) printf("<div><label> %s \
						 : <input name = %s size = %d></ label></ div>\n", \
											NAME, INPUT, SIZE)

/**
 * \brief Macro para o botão do form
*/
#define FORM_BUTTON(NAME) printf("<div><input type=%s value=%s></div>\n", "submit", NAME)



/**
 * \brief Macro para fechar o form
*/
#define CLOSE_FORM printf("</form>\n")

#endif
