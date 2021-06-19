#!/bin/bash
ROOT_UID=0
SUCCESS=0

# Run as root, of course. (this might not be necessary, because we have to run the script somehow with root anyway)
if [ "$UID" -ne "$ROOT_UID" ]
then
  echo "Se debe estar como root para ejecutar este script"
  exit $E_NOTROOT
fi  

file=$1

if [ "${file}X" = "X" ];
then
   echo "Debe indicar el archivo con el listado de usuarios a agragar..."
   exit 1
fi

# Del archivo con el listado de usuarios a eliminar:
# Este es el formato:
# ejemplo
#    |   
#    f1  
#$f1 = username

crearUsuario(){
	echo " "
	echo " "
	echo "---->Agregar  Usuario <----"
	eval username="$1"
	eval password="$2"
	eval userid="$3"
	eval groupid="$4"
	eval useridinfo="$5"
	eval hmdirectory="$6"
	eval cmshell="$7" 
	echo "$HOME"
	#EXISTENCIA DE USUARIOS
	if grep -q ${groupid} /etc/group
	then
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "EL GRUPO "${groupid}" YA HA SIDO CREADO..."
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"	
	else
	echo " "
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "El GRUPO "${groupid}" NO EXISTE, POR LO TANTO NO SE HA PODIDO CREAR EL USUARIO..."
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	fi
	#EXISTENCIA DE USUARIOS
	if grep -q "${username}" /etc/passwd
	then
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"	
	echo "EL USUARIO "${username}" YA HA SIDO CREADO..."
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	else
	echo " "
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "EL USARIO "${username}" NO HA SIDO CEADO..."
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "+++++++++++++++++++SE AGREGARA UN USUARIO+++++++++++++++++++++++++ "
	echo "------------------------------------------------------------------"
	echo "USUARIO: "${username}" - CONTRASEÑA: "${password}"...." 
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "SU ID DE USUARIO ES: "${userid}"... "	
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"	
	echo "El ID DEL GRUPO ES: "${groupid}".... "
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "EL COMAND SHELL ES: "${cmshell}".... "
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "EL INFORMACION DE USUARIO ID ES: "${useridinfo}".... "
	echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo " "
	#AGREGAMOS EL USUARIO	
	useradd -u "${userid}" -c "${useridinfo}"  -p "${password}"  -s "${cmshell}" -g  "${groupid}" -m -d "${hmdirectory}" "${username}" 
	echo "$username:$password" | chpasswd --md5
	chage  -d 0 ${username} 	
	echo ${username}>>eliminar_usuarios.csv
	fi
	
}
	


while IFS=: read  -r f1 f2 f3 f4 f5 f6 f7 
do
	crearUsuario "\${f1}" "\${f2}" "\${f3}" "\${f4}" "\${f5}" "\${f6}" "\${f7}" 
done < ${file}
exit 0

