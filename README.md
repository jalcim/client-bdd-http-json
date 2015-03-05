# client-bdd-http-json
un client/bdd sous forme d'objet qui interroge un serveur sous forme http et transfert encodé json

{
 2 fichier tres important
 id : contient l'id le mdp et l'ip
 request_file : contient les requettes
}

le type de l'objet est t_object
(t_object *object;)

les methodes sont initialiser dans m_object_init
(m_object_init lance aussi les processus de la bdd comme ceux du client)


______________________________________________________________________________________________________


comme methode il y a :

m_object_init : creation de l'objet ses processus et de ses methodes et de ses structures

m_object_request_server(cmd) : requette au serveur suivant la cmd(numero de ligne dans le fichier request_file)
 
 cmd = 0 = login; cmd = 1 = logout; cmd = 2 = reception d'un fichier json;

m_object_request_bdd_send(" ") : envoi du json a la bdd

m_object_request_bdd_extract("filename") : extraction d'un fichier client parser

m_object_request_bdd_id(" ") : extraction de tous les ids clients et de leur nom dans un objet json

m_object_request_bdd_del("filename") : destruction d'un fichier client

m_object_destruct : destruction de l'objet

les methodes sont sous forme de pointeur de fonction dans les structure de l'objet voir object.h

des defines sont mit en place dans object.h pour l'encapsulation

les exemples d'utilisation sont dans object.c


____________________________________________________________________________________________


pour une interaction avec le langage C utiliser ces fonctions :

write_elem_json(t_json *json, int fd) : ecrit 1 element json (liste chaine) sur la sortie indiquer par le fd

write_json(t_json) : creer un fichier par element json (1 liste chaine == 1 fichier) /!\ecrit tous les json/!\
le nom est l'ID


_________________________________________________________________________________________________


pour une interaction C -> objective-C  : (char *) -> (NSString *) utiliser :

//char *str = malloc(20);strcpy(str, "hello world !);
NSString *String = [NSString stringWithCString:str encoding: NSUTF8StringEncoding];


_________________________________________________________________________________________________________


le multi client est theoriquement possible mais il faudrais organiser un dossier par client (pas le cas)

le repertoire reg contient les fichiers parser sous forme nom, variable ainsi qu'une table des ids

les fichiers dans le repertoire reg sont issue du fichier json recu du serveur

les requettes serveur sont dans le fichier request_file

les requettes serveur sont assembler dans config_request.c

les requettes bdd sont implenter en dur dans bdd.c/request_bdd/!proto

les sorties d'erreur de la bdd sont dans error_out
