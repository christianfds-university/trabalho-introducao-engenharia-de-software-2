cmake_minimum_required(VERSION 3.6)
project(TrabIES)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp View/Menu.cpp View/Menu.h Model/Condutor_Model.cpp Model/Condutor_Model.h Model/Veiculo_Model.cpp Model/Veiculo_Model.h Model/Infracao_Model.cpp Model/Infracao_Model.h DAO/Condutor_DAO.cpp DAO/Condutor_DAO.h DAO/Veiculo_DAO.cpp DAO/Veiculo_DAO.h DAO/DAO.h DAO/Infracao_DAO.cpp DAO/Infracao_DAO.h Controller/Condutor_Controller.cpp Controller/Condutor_Controller.h View/Condutor_View.cpp View/Condutor_View.h View/Utils.cpp View/Utils.h Controller/Veiculo_Controller.cpp Controller/Veiculo_Controller.h View/Veiculo_View.cpp View/Veiculo_View.h)
add_executable(TrabIES ${SOURCE_FILES})