#include <cstdio>
#include <iostream>
#include <cstring> 


int main() {
	
		// ifconfig file connect
        FILE * fp = popen("/sbin/ifconfig eth0", "r");

        if (fp) {
                
		//set condition to obtain only the ip address		
		char *x=NULL, *y; size_t z;

                while ((getline(&x, &z, fp) > 0) && x)
		 {
					//to find the "inet"" in the list of the ifconfig
                   if (x = strstr(x, "inet ")) {
                        x+=5;
						
						//to obtain the ip address format with ':'
                        if (x = strchr(x, ':')) {
                            ++x;
							
							// when the system meet ' ', system stop search and display the result.
                            if (y = strchr(x, ' ')) {
                                 *y='\0';
                                 printf("Local IP Address: %s\n", x);
                            }
                        }
                   }
              }
        }
        pclose(fp);
        return 0;
}
