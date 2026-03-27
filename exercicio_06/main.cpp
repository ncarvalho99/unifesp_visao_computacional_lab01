#include <iostream>
#include <vector>
#include <string>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img_cinza = cv::imread("imagem.jpg", cv::IMREAD_GRAYSCALE);

    if (img_cinza.empty()) {
        std::cerr << "Erro ao abrir a imagem." << std::endl;
        return 1;
    }

    cv::imshow("Original (256 niveis)", img_cinza);
    std::vector<int> niveis = {128, 64, 16, 4};

    for (int k : niveis) {
        cv::Mat img_quantizada = img_cinza.clone();

        int fator = 256 / k; 

        for (int y = 0; y < img_quantizada.rows; y++) {
            for (int x = 0; x < img_quantizada.cols; x++) {
                
                int valor_antigo = img_quantizada.at<uchar>(y, x);
                int novo_valor = (valor_antigo / fator) * fator;
                
                img_quantizada.at<uchar>(y, x) = novo_valor;
            }
        }
        std::string nome_janela = "Quantizada - " + std::to_string(k) + " niveis";
        std::string nome_arquivo = "imagem_quantizada_" + std::to_string(k) + ".jpg";
        cv::imshow(nome_janela, img_quantizada);
        cv::imwrite(nome_arquivo, img_quantizada);
    }
    cv::waitKey(0);

    return 0;
}