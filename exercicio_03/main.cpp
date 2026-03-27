#include <iostream>
#include <opencv2/opencv.hpp>

int main() {
    cv::Mat img = cv::imread("imagem.jpg", cv::IMREAD_GRAYSCALE);
    if (img.empty()) {
        std::cerr << "Erro ao abrir a imagem." << std::endl;
        return 1;
    }
    int x, y;

    std::cout << "A imagem tem tamanho " << img.cols << "x" << img.rows << "." << std::endl;
    std::cout << "Digite a coordenada X (coluna, de 0 a " << img.cols - 1 << "): ";
    std::cin >> x;
    std::cout << "Digite a coordenada Y (linha, de 0 a " << img.rows - 1 << "): ";
    std::cin >> y;
    if (x >= 0 && x < img.cols && y >= 0 && y < img.rows) {
        int intensidade = (int)img.at<uchar>(y, x);
        
        std::cout << "--> A intensidade no pixel (" << x << ", " << y << ") e: " << intensidade << std::endl;
    } else {
        std::cout << "Erro: Coordenadas fora dos limites da imagem!" << std::endl;
    }
    cv::imshow("Imagem em Tons de Cinza", img);
    cv::waitKey(0);

    return 0;
}