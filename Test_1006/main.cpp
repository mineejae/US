#include <stdio.h>
#include <iostream>

//�ֹι�ȣ �Է� ������ ��������̶� ���� ǥ�� ���α׷�
// 13�� �̻��̸� �߸���
// 32�ϻ� �̻��̸� �߸���
// �ڿ� ��ȣ ù°�ڸ��� 1, 3 : ����
// �ڿ� ��ȣ ù°�ڸ��� 2, 4 : ����

//830714-1
// ���࿡ �߸��� �ֹι�ȣ��� "�߸� �Է��ϼ̽��ϴ�" ���

//>�ֹι�ȣ �տ� �ڸ��� �Է����ּ��� : 830714
//>�ֹι�ȣ �ڿ� ù°�ڸ��� �Է����ּ��� : 1
//>83�� 07�� 14�� ���� ���

// ���� �ϳ��� �Է��ϼ��� : 3
// ���� �ϳ��� �� �Է��ϼ��� : 30

// ���
// R = ù��° ���ڿ� �ι�° ���� ���̿� ���ڸ� ��� ���Ѱ�
// "3�� 30���̿� ��� ���� ���ϸ� %d�Դϴ�.", R

//�Լ� �̸� : standardWeight
//�ɹ� ���� : float height
//���� �� : float
//���� : (height - 100) * 0.9
float standardWeight(float height)
{
    return(height - 100) * 0.9;
}

//�Լ� �̸� : GetBMI
//�ɹ� ���� : float weight, float standardWeight
//���� �� : float
//���� : (weight - standardWeight)  * 100 / standardWeight
float GetBMI(float weight, float standardWeight)
{
    return (weight - standardWeight) * 100 / standardWeight;
}

// ���� �ݺ�, 0 �Է½� ����

BMI�� ����Ͻðڽ��ϱ� ? 0)No 1)Yes
�����Ը� �Է����ּ��� : weight�� �� �Է�
Ű�� �Է����ּ��� : height�� �� �Է�
bmi�� ���� ��� ����
���        �񸸵� ��ġ
10����        ����
10�ʰ� 20����    ��ü��
20 �ʰ�        ��


int main()
{
   
    bool bRun = true;

    while(bRun)
    {
        printf("BMI�� ����Ͻðڽ��ϱ�? 0)No 1)Yes : ");
        int input = 0;
        scantf_s("%d" , &input);

        switch (input)
        {
        case 0:
            bRun = falsse;
            break;

        case 1:
        {
            int weight = 0, height = 0, BMI = 0;
            printf("�����Ը� �Է����ּ��� : ");
            scanf_s("%d", &weight);
            printf("Ű�� �Է����ּ��� : ");
            scanf_s("%d", &height);
            BMI = GetBMI(weight, standardWeight(height));

            if (10 <= BMI){ 
                printf("����\n"); 
            }
            else if (10 < BMI && BMI <= 20) {
                printf("��ü��\n");
            }
            else if (20 > BMI) {
                printf("��\n");
            }
        }
            break;
        
        default:
            break;
        }

    int a = 0;
    int b = 0;

    printf("\n���� �ϳ��� �Է��ϼ���:");
    scanf_s("%d", &a);
    printf("\n���� �ϳ� �� �Է��ϼ���:");
    scanf_s("%d", &b);


    

    int R = 0;

    for (int i = a; i <= b ; i++)
    {
        R = R +i;
    }


    printf("%d�� %d������ ��� ���� ���ϸ� %d�Դϴ�\n", a, b, R);

    int a = 0;
    int value = 0;
    int per = 0;

    printf("\n�ҵ漼�� ����Ͻðڽ��ϱ�? 0)No 1)Yes");
    scanf_s("%d", &a);
    if (a == 1)
    {
        printf("\n���� �� �ҵ��� �Է��ϼ���(���� ����) :");
        scanf_s("%d", &value);

        if (value > 100000)
        {
            per = 45;
        }
        else if (50000 < value)
        {
            per = 42;
        }
        else if (30000 < value)
        {
            per = 40;
        }
        else if (15000 < value)
        {
            per = 38;
        }
        else if (8800 < value)
        {
            per = 35;
        }
        else if (4600 < value)
        {
            per = 24;
        }
        else if (1200 < value)
        {
            per = 15;
        }
        else
        {
            per = 6;
        }
        printf("����� �ҵ漼�� %d �ۼ�Ʈ ������\n", per);
    }
    else
    {
        return 0;
    }
}

      
}


    
  

   
