#ifndef MYTIMER_HPP
#define MYTIMER_HPP

#include<iostream>
#include<chrono>


class FPS_Adjaster{
  private:
    bool is_started_;
    std::chrono::time_point<std::chrono::system_clock> start_;
    std::chrono::time_point<std::chrono::system_clock> end_;
    std::chrono::duration<std::chrono::system_clock::duration> duration_;
  public:  
    FPS_Adjaster(int fps):is_started_(false){
        duration_= std::chrono::duration_cast<std::chrono::system_clock::duration>(std::chrono::milliseconds(1));
        
    }
    void SetPoint(){
        start_ = std::chrono::system_clock::now();
        is_started_ = true;
    }
    bool isPassedTime(){
        if(!is_started_){
            std::cerr << "FPS_Adjaster : Start point is not updated!" << std::endl;
            return true;
        }else{
            return std::chrono::system_clock::now() - start_ > duration_;
        }
    }
    
    
};


#endif
