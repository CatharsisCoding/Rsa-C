#include<stdio.h>  
#include<stdlib.h>  
#include<math.h>  


/**
 * Calcule d (rappel : d * e congru 1 mod phi )
 *
 * Voici la vidéo qui m'a inspiré : https://www.youtube.com/watch?v=lPNYszuJUGM, j'ai juste codé exactement les étapes qu'il fait.
 * Tout d'abord, il prend phi, le multiplie par 1 puis ajoute 1. Si le résultat est divisible par e, alors on le garde.
 * Sinon, on continue en multipliant par 2 cette fois ci et on ajoute 1 sinon on multiplie par 3, etc., jusqu'à ce que cela soit divisible par e.
 * Une fois que l'on a trouvé ce chiffre, on le divise par e et cela nous donne d.
 *
 * @param phi La base de l'exponentiation.
 * @param e L'exposant de l'exponentiation.
 * @return int Le d dont on à besoin pour chiffrer et dechiffrer
 */

int calcul_d(int phi , int e){
    int temp;
    int i=1;
    while(1){
        temp=0;
        temp= (phi*i)+1;
        if(temp % e == 0){
            return ((i*phi)+1)/e;
        }
        i++;
    }
}

/**
 * Calcule la puissance modulaire rapide
 *
 * Calcule (base^exp) % mod  efficacement grace à l'exponentiation binaire modulaire.
 * Plus rapide que la methode naive car moins de multiplication
 * 
 * @param base La base
 * @param exp L'exposant
 * @param mod Le modulo.
 * @return int Le résultat de (base^exp) % mod.
 */
int mod_pow(int base, int exp, int mod) {
    int result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        exp = exp >> 1; //On utilise le décalage binaire vers la droite (>> 1) pour diviser exp par 2. 
        base = (base * base) % mod;
    }
    return result;
}


/**
 * Calcul secret = message^e mod n
 * Chiffre un message en utilisant l'exponentiation modulaire (sinon cela prendrai trop de temps et cela donnerai des resultats faux).
 *
 * @param message Le message à chiffrer (sous forme d'un entier). /!\ Important /!\ le message doit etre plus petit que n , ici 100< 3611
 * @param e L'exposant public de la clé.
 * @param n Le modulo de la clé publique.
 * @return int Le message chiffré.
 */
int chiffrer(int message, int e, int n){
    return mod_pow(message, e, n);
}

/**
 * Calcul message = secret^d mod n
 * Déchiffre un message chiffré en utilisant l'exponentiation modulaire. (sinon cela prendrai trop de temps et cela donnerai des resultats faux)
 *
 * @param secret Le message chiffré (sous forme d'un entier).
 * @param d L'exposant privé de la clé.
 * @param n Le modulo de la clé privée.
 * @return int Le message déchiffré.
 */
int dechiffrer(int secret, int d, int n){
    return mod_pow(secret, d, n);
}


int main(){

    int p = 23; // p nombre premier
    int q = 157; // q nombre premier

    int n= p*q;
    int phi=(p-1)*(q-1);
    printf("phi= %d\n",phi);
    int e = 17; // attention e doit etre compatible , rappel : pgcd(e,phi)=1
     printf("clé publique :  n= %d et e= %d\n",n,e);
    int d = calcul_d(phi,e);

    printf("clé privée d = %d\n", d);

    int message=1911; // attention le message doit etre plus petit que n , ici par exemple 100< 3611
    int secret=chiffrer(message,e,n);
    int dechiffre= dechiffrer(secret,d,n);
    printf("le nombre %d est chiffrée : %d\n",message,secret);
    printf("le secret %d est déchiffré : %d",secret,dechiffre);    

    return EXIT_SUCCESS;
}