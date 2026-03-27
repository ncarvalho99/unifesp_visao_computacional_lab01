#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img_cinza = cv::imread("imagem.jpg", cv::IMREAD_GRAYSCALE);
    if (img_cinza.empty()) {
        std::cerr << "Erro ao abrir a imagem." << std::endl;
        return 1;
    }
    cv::Mat img_binaria = img_cinza.clone();

    int limiar = 128;
    for (int y = 0; y < img_cinza.rows; y++) {
        for (int x = 0; x < img_cinza.cols; x++) {
            int intensidade = img_cinza.at<uchar>(y, x);
            
            if (intensidade >= limiar) {
                img_binaria.at<uchar>(y, x) = 255;
            } else {
                img_binaria.at<uchar>(y, x) = 0;
            }
        }
    }
    cv::imshow("Imagem em Tons de Cinza", img_cinza);
    cv::imshow("Imagem Binaria (Preto e Branco)", img_binaria);
    cv::imwrite("imagem_binaria.jpg", img_binaria);
    cv::waitKey(0);

    return 0;
}