#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img_original = cv::imread("imagem.jpg", cv::IMREAD_GRAYSCALE);

    if (img_original.empty()) {
        std::cerr << "Erro ao abrir a imagem." << std::endl;
        return 1;
    }
    cv::Mat img_temp, img_amostrada;
    cv::resize(img_original, img_temp, cv::Size(), 0.25, 0.25);
    cv::resize(img_temp, img_amostrada, img_original.size()); 
    cv::Mat img_quantizada = img_original.clone();

    int niveis = 8;
    int fator = 256 / niveis;
    
    for (int y = 0; y < img_quantizada.rows; y++) {
        for (int x = 0; x < img_quantizada.cols; x++) {
            int antigo = img_quantizada.at<uchar>(y, x);
            img_quantizada.at<uchar>(y, x) = (antigo / fator) * fator;
        }
    }
    cv::Mat img_combinada = img_amostrada.clone();
    
    for (int y = 0; y < img_combinada.rows; y++) {
        for (int x = 0; x < img_combinada.cols; x++) {
            int antigo = img_combinada.at<uchar>(y, x);
            img_combinada.at<uchar>(y, x) = (antigo / fator) * fator;
        }
    }
    cv::imshow("1. Original", img_original);
    cv::imshow("2. Perda de Detalhe Espacial (Amostragem)", img_amostrada);
    cv::imshow("3. Perda de Suavidade Tonal (Quantizacao)", img_quantizada);
    cv::imshow("4. Efeitos Combinados", img_combinada);
    cv::imwrite("img_amostrada.jpg", img_amostrada);
    cv::imwrite("img_quantizada.jpg", img_quantizada);
    cv::imwrite("img_combinada.jpg", img_combinada);
    cv::waitKey(0);

    return 0;
}