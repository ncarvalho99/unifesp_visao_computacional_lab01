#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img_original = cv::imread("imagem.jpg", cv::IMREAD_GRAYSCALE);

    if (img_original.empty()) {
        std::cerr << "Erro ao abrir a imagem." << std::endl;
        return 1;
    }
    cv::Mat img_reduzida;
    cv::Mat img_reampliada;
    cv::resize(img_original, img_reduzida, cv::Size(), 0.5, 0.5);
    cv::resize(img_reduzida, img_reampliada, img_original.size());
    cv::imshow("1. Imagem Original", img_original);
    cv::imshow("2. Imagem Reduzida", img_reduzida);
    cv::imshow("3. Imagem Reampliada", img_reampliada);
    cv::imwrite("imagem_reduzida.jpg", img_reduzida);
    cv::imwrite("imagem_reampliada.jpg", img_reampliada);
    cv::waitKey(0);

    return 0;
}