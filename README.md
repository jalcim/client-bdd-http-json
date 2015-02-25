# client-bdd-http-json
un client/bdd sous forme d'objet qui interroge un serveur sous forme http et transfert sous json

le type de l'objet (classe) est t_object

les methodes sont initialiser dans m_object_init

comme methode il y a : m_object_init, m_object_request_server(cmd), m_object_request_bdd_send(filename)
,m_object_request_bdd_extract(filename), m_object_request_bdd_id(filename), m_object_request_bdd_del(filename)
,m_object_destruct

les methodes sont sous forme de pointeur de fonction

et des defines sont mit en place dans object.h pour l'encapsulation

les exemples d'utilisation sont dans object.c

le multi client est possible mais il faudrais organiser un dossier par client (pas le cas)

le repertoire reg contient les fichiers parser sous forme nom, variable

les fichiers dans le repertoire reg sont issue du fichier json recu du serveur

les requettes serveur sont dans le fichier request_file

les requettes serveur sont assembler dans config_request

les requettes bdd sont implenter en dur dans bdd.c/request_bdd/!proto

les sorties d'erreur de la bdd sont dans error_out
