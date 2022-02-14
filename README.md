# Miruy

## 1、编译所需依赖库：  

- ### yaml-cpp：  

    > 源码地址：[https://github.com/jbeder/yaml-cpp](https://github.com/jbeder/yaml-cpp)  
    > 
    > 编译为动态库：进入 **`CMakeList.txt`** 路径，执行命令：
    > ```bash
    > mkdir build && cd build  
    > cmake -DBUILD_SHARED_LIBS=ON .. && make  
    > sudo make install  
    > ```



## 2、编译：  

### 执行以下命令：  
> ```bash 
> mkdir build && cd build  
> cmake ..  
> make  
> ```
