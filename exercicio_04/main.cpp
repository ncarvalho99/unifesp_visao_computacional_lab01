#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img_cinza = cv::imread("imagem.jpg", cv::IMREAD_GRAYSCALE);

    if (img_cinza.empty()) {
        std::cerr << "Erro ao abrir a imagem." << std::endl;
        return 1;
    }

    cv::Mat img_negativa = img_cinza.clone();

    for (int y = 0; y < img_cinza.rows; y++) {
        for (int x = 0; x < img_cinza.cols; x++) {
            int antigo = img_cinza.at<uchar>(y, x);
            int novo = 255 - antigo;
            img_negativa.at<uchar>(y, x) = novo;
        }
    }
    cv::imshow("Imagem em Tons de Cinza", img_cinza);
    cv::imshow("Imagem Negativa", img_negativa);
    cv::imwrite("imagem_negativa.jpg", img_negativa);
    cv::waitKey(0);

    return 0;
}