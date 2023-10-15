#include "RSA_Class.hpp"

int main()
{
    // init an instance
    RSA instance;

    cout << endl << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
    cout << "选择加密(0)/解密(1)： ";
    int choose;
    while(1)
	{
		cin >> choose;
		getchar();
		if((choose != 0) && (choose != 1))
			cout << "输入错误，重新输入0或1：";
		else
			break;
	}

    if (choose == 0)
    {
        cout << "是否生成密钥:是(1)/否(0)？ ";
        int choose2;
        while(1)
	    {
		    cin >> choose2;
		    getchar();
		    if((choose2 != 0) && (choose2 != 1))
			    cout << "输入错误，重新输入0或1：";
		    else
			    break;
	    }

        if (choose2 == 1)
        {
            instance.GenerateLargePrime();
            instance.KeyGeneration();
            cout << "密钥生成完毕，存储至key_e.txt、key_d.txt、key_n.txt。"  << endl << endl;

            cout << "请输入要加密的明文:" << endl;
            string plaintextStr;
            // getline(cin, plaintextStr);
            plaintextStr = "this is the sentence that will be encrypt";
            instance.AddPlainStrToHexPlaintext(plaintextStr);
            cout << "instance.plaintext: " << instance.plaintext << endl;

            instance.RSA_Encrypt();
        }


    }

    return 0; 
}

