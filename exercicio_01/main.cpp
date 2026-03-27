#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("imagem.jpg");
    if (img.empty()) {
        std::cerr << "Erro ao abrir a imagem. Verifique se o arquivo 'imagem.jpg' esta na mesma pasta do executavel." << std::endl;
        return 1;
    }
    std::cout << "Largura: " << img.cols << " pixels" << std::endl;
    std::cout << "Altura: " << img.rows << " pixels" << std::endl;
    std::cout << "Canais: " << img.channels() << std::endl;
    cv::imshow("Imagem Original", img);
    cv::waitKey(0);

    return 0;
}