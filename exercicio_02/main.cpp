#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("imagem.jpg");

    if (img.empty()) {
        std::cerr << "Erro ao abrir a imagem." << std::endl;
        return 1;
    }
    cv::Mat img_cinza;
    cv::cvtColor(img, img_cinza, cv::COLOR_BGR2GRAY);
    cv::imshow("Imagem Original", img);
    cv::imshow("Imagem em Tons de Cinza", img_cinza);
    cv::imwrite("imagem_cinza.jpg", img_cinza);
    cv::waitKey(0);

    return 0;
}