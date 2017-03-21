<!DOCTYPE html>

<html>

	<head>
		<title>Mi DinDNS</title>
		<meta charset="UTF-8">
	</head>

	<body>
		
		<?php 

			$ficheros = glob("lugares/*.html");

			foreach ($ficheros as $indice => $fichero) {
				
				print_r( glob("lugares/*.html") );
				echo $fichero;
			}

		?>

	</body>

</html>

sudo service cron