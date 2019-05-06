<?php
/**
 * @version 1.0
 */

require("class.phpmailer.php");
require("class.smtp.php");

// Valores enviados desde el formulario
if ( !isset($_POST["nombre"]) || !isset($_POST["email"]) || !isset($_POST["mensaje"]) ) {
    die ("Es necesario completar todos los datos del formulario");
}
$nombre = $_POST["nombre"];
$email = $_POST["email"];
$mensaje = $_POST["mensaje"];

// Datos de la cuenta de correo utilizada para enviar vía SMTP
$smtpHost = "usuario.ferozo.com";  // Dominio alternativo brindado en el email de alta 
$smtpUsuario = "miCuenta@miDominio.com";  // Mi cuenta de correo
$smtpClave = "miClave";  // Mi contraseña

// Email donde se enviaran los datos cargados en el formulario de contacto
$emailDestino = "martinsamb@gmail.com";

$mail = new PHPMailer();
$mail->IsSMTP();
$mail->SMTPAuth = true;
$mail->Port = 465; 
$mail->SMTPSecure = 'ssl';
$mail->IsHTML(true); 
$mail->CharSet = "utf-8";


// VALORES A MODIFICAR //
$mail->Host = $smtpHost; 
$mail->Username = $smtpUsuario; 
$mail->Password = $smtpClave;

$mail->From = $email; // Email desde donde envío el correo.
$mail->FromName = $nombre;
$mail->AddAddress($emailDestino); // Esta es la dirección a donde enviamos los datos del formulario

$mail->Subject = "DonWeb - Ejemplo de formulario de contacto"; // Este es el titulo del email.
$mensajeHtml = nl2br($mensaje);
$mail->Body = "{$mensajeHtml} <br /><br />Formulario de ejemplo. By DonWeb<br />"; // Texto del email en formato HTML
$mail->AltBody = "{$mensaje} \n\n Formulario de ejemplo By DonWeb"; // Texto sin formato HTML
// FIN - VALORES A MODIFICAR //

$estadoEnvio = $mail->Send(); 
if($estadoEnvio){
    echo "El correo fue enviado correctamente.";
} else {
    echo "Ocurrió un error inesperado.";
}

<!doctype html>
<html lang="en">
  <head>
    <!-- Required meta tags -->
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <!-- Bootstrap CSS -->
    <link rel="stylesheet" href="css/bootstrap.css">
  <link rel="stylesheet" href="css/font-awesome.min.css">
  <link rel="stylesheet" href="css/estilos.css">
  <link rel="shortcut icon" type="image/x-icon" href="logo.ico"/>

  <title>HIDRÁULICA RANDAZZO</title>
  <style type="text/css">
  iframe { padding: 20px; }
</style>
  </head>
  <body>
      <!-- Inicio de navegación -->
  <nav class="navbar navbar-expand-lg navbar-light bg-light">
    <a class="navbar-brand" href="#">
      <img src="images/logo_ir.svg" height="60" class="d-inline-block align-top" alt="Logo-randazzo">
    </a>
    <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
      <span class="navbar-toggler-icon"></span>
    </button>

    <div class="collapse navbar-collapse" id="navbarSupportedContent">
      <ul class="navbar-nav mr-auto">
        <li class="nav-item">
          <a class="nav-link" href="index.html">Inicio <span class="sr-only">(current)</span></a>
        </li>
        <li class="nav-item dropdown">
          <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            Producto
          </a>
          <div class="dropdown-menu" aria-labelledby="navbarDropdown">
            <a class="dropdown-item" href="01_hidraulica.html">Hidráulica Industrial y Móvil
               <img src="images/logo_rexroth.png" height="20" class="d-inline-block align-center" alt="logo-rexroth">
            </a>
            <a class="dropdown-item" href="02_neumatica.html">Neumática Industrial
              <img src="images/logo_aventics.png" height="30" class="d-inline-block align-center" alt="logo-aventics">
            </a>
            <a class="dropdown-item" href="14_neumatica.html">Neumática Industrial
              <img src="images/logo_pneumax.png" height="30" class="d-inline-block align-center" alt="logo-pneumax">
            </a>
            <a class="dropdown-item" href="03_tecnologia.html">Tecnología de Movimiento
               <img src="images/logo_rexroth.png" height="20" class="d-inline-block align-center" alt="logo-rexroth">
            </a>
            <a class="dropdown-item" href="04_controles.html">Controles y accionamiento eléctricos
               <img src="images/logo_rexroth.png" height="20" class="d-inline-block align-center" alt="logo-rexroth">
            </a>
            <a class="dropdown-item" href="05_montaje.html">Tecnología de Montaje
               <img src="images/logo_rexroth.png" height="20" class="d-inline-block align-center" alt="logo-rexroth">
            </a>
            <div class="dropdown-divider"></div>
            <a class="dropdown-item" href="15_catalogoHidraulico.html">Catálogo Hidráulica 
              <img src="images/logo_rexroth.png" height="20" class="d-inline-block align-center" alt="logo-rexroth">
            </a>
          </div>
        </li>
        <li class="nav-item dropdown">
          <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
            Servicios
          </a>
          <div class="dropdown-menu" aria-labelledby="navbarDropdown">
            <a class="dropdown-item" href="06_asistencia.html">Asistencia técnica</a>
            <a class="dropdown-item" href="08_reparaciones.html">Reparaciones</a>
            <a class="dropdown-item" href="09_mecanizados.html">Mecanizados</a>
            <a class="dropdown-item" href="10_fabricacion.html">Fabricación</a>
          </div>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="11_capacitacion.html">Capacitación</a>
        </li>
        <li class="nav-item">
          <a class="nav-link active" href="12_contacto.html">Contacto</a>
        </li>
      </ul>
    </div>
    <a class="navbar-brand" href="#">
      <img src="images/logo-rex.png"  height="60" class="d-inline-block align-middle" alt="logo-rexroth">
    </a>
  </nav>    
  <!-- Fin de navegación -->

  <!-- Fin de navegación -->
  <!-- Breadcrumb-->
  <nav aria-label="breadcrumb">
    <ol class="breadcrumb">
      <li class="breadcrumb-item active" aria-current="page">Contacto</li>
    </ol>
  </nav>

  <!-- Fin Breadcrumb -->


 <!-- columnas -->
  <section>
    <div class="container">
      <h2 class="section-title black">Contacto</h2> <!-- /.section-title -->
        <h2>Contáctese con nosotros</h2>
        <div class="row">
          <div class="co-xs-12 col-sm-6 col-md-6 col-lg-6">
            <!--
            <input type="text" name="nombre" placeholder="Ingrese su nombre" required>
            <input type="text" name="correo" placeholder="Ingrese su correo" required>
            <input type="text" name="telefono" placeholder="Ingrese su celular" required>
            <input type="text" name="empresa" placeholder="Empresa opcional" required>
            <textarea name="mensaje" placeholder="Escriba aquí su mensaje" required></textarea>
            <input type="submit" value="Enviar" id="boton">
            -->
            <div><? echo $error.$mensajeExito; ?></div>
        <div class="container">  
          <form id="contact" action="contacto.php" method="post">
            <fieldset>
              <input  name="nombre" placeholder="Tu nombre" type="text" tabindex="1" required autofocus >
            </fieldset>
            <fieldset>
              <input name="email" placeholder="Tu email" type="email" tabindex="2" required>
            </fieldset>
            <fieldset>
              <textarea name="mensaje" placeholder="Escribe tu mensaje...." tabindex="5" required></textarea>
            </fieldset>
            <fieldset>
              <button name="submit" type="submit" id="contact-submit" data-submit="...Enviar">Enviar</button>
            </fieldset> 
          </form>
        </div>
            <ul>
              <li class="list-inline-item">Ing. Nestor J. Randazzo</li>
              <li class="list-inline-item"><i class="fa fa-mobile fa-2x" aria-hidden="true"></i></li>
              <li class="list-inline-item">  011 1549926711</li>
              <li class="list-inline-item">Ing. Damián O. Randazzo</li>
              <li class="list-inline-item"><i class="fa fa-mobile fa-2x" aria-hidden="true"></i></li>
              <li class="list-inline-item">  011 1566956878</li>
            </ul>
          </div>
          <div class="co-xs-12 col-sm-6 col-md-6 col-lg-6">
            <iframe 
              src="https://www.google.com/maps/embed?pb=!1m18!1m12!1m3!1d3282.6400447838478!2d-58.70268498474471!3d-34.63853556684819!2m3!1f0!2f0!3f0!3m2!1i1024!2i768!4f13.1!3m3!1m2!1s0x95bcbfaf8151d2d1%3A0x2756e8e153234bde!2sIngenier%C3%ADa+Randazzo+S.H.!5e0!3m2!1ses!2sar!4v1541007520220" width="100%" height="450" frameborder="0" style="border:0" allowfullscreen>
            </iframe>
          </div>
        </div>  
    </div>
  </section>
  <!--- Fin de columnas ->

  <!-  Inicio Footer -->
  
  <!-- Footer -->
  <section id="footer">
    <div class="container">
      <div class="row text-center text-xs-center text-sm-left text-md-left">
        <div class="col-xs-12 col-sm- col-md-2">
          <h5><a href="index.html"><i class="fa fa-angle-double-right"></i> Inicio</a></h5>
        </div>
        <div class="col-xs-12 col-sm-3 col-md-3">
          <h5>Productos</h5>
          <ul class="list-unstyled quick-links">
            <li><a href="01_hidraulica.html"><i class="fa fa-angle-double-right"></i>Hidráulica Industrial y Móvil</a></li>
            <li><a href="02_neumatica.html"><i class="fa fa-angle-double-right"></i>Neumática Industrial</a></li>
            <li><a href="03_tecnologia.html"><i class="fa fa-angle-double-right"></i>Tecnología de movimiento lineal</a></li>
            <li><a href="04_controles.html"><i class="fa fa-angle-double-right"></i>Controles y accionamientos eléctricos</a></li>
            <li><a href="05_montaje.html"><i class="fa fa-angle-double-right"></i>Tecnología de montaje</a></li>
          </ul>
        </div>
        <div class="col-xs-12 col-sm-3 col-md-3">
          <h5>Servicios</h5>
          <ul class="list-unstyled quick-links">
            <li><a href="06_asistencia.html"><i class="fa fa-angle-double-right"></i>Asistencia Técnica</a></li>
            <li><a href="08_reparaciones.html"><i class="fa fa-angle-double-right"></i>Reparaciones</a></li>
            <li><a href="09_mecanizados.html"><i class="fa fa-angle-double-right"></i>Mecanizados</a></li>
            <li><a href="10_fabricacion.html"><i class="fa fa-angle-double-right"></i>Fabricación</a></li>
          </ul>
        </div>
        <div class="col-xs-12 col-sm-2 col-md-2">
          <h5><a href="11_capacitacion.html"><i class="fa fa-angle-double-right"></i> Capacitación</a></h5>
        </div>
        <div class="col-xs-12 col-sm-2 col-md-2">
          <h5><a href="12_contacto.html"><i class="fa fa-angle-double-right"></i> Contacto</a></h5>
        </div>
      </div>
      <div class="row">
        <div class="col-xs-12 col-sm-12 col-md-12 mt-2 mt-sm-2">
          <ul class="list-unstyled list-inline social text-center">
            <li class="list-inline-item"><a href="" target="_blank"><i class="fa fa-facebook"></i></a></li>
            <li class="list-inline-item"><a href=""><i class="fa fa-twitter"></i></a></li>
            <li class="list-inline-item"><a href="" target="_blank"><i class="fa fa-instagram"></i></a></li>
            <li class="list-inline-item"><a href="mailto:ingran@infovia.com.ar" target="_blank"><i class="fa fa-envelope"></i></a></li>
          </ul>
        </div>
        </hr>
      </div>  
      <div class="row">
        <div class="col-xs-12 col-sm-12 col-md-12 mt-2 mt-sm-2 text-center text-white">
          <p>Todos los derechos reservados<a class="text-green ml-2" href="http://ingenieriarandazzo.com.ar/" target="_blank">www.ingenieriarandazzo.com.ar</a></p>
          <p>Creado por:<a href="mailto:martinsamb@gmail.com" target="_blank">  Martín Sambrano</a></p>
          <p class="h6">Copyright&copy 2019 Ingeniería Randazzo.</p>
        </div>
        </hr>
      </div>  
    </div>
  </section>
  <!-- ./Footer --> 

  
  <!-- Fin de Footer -->


    <!-- Optional JavaScript -->
    <!-- jQuery first, then Popper.js, then Bootstrap JS -->
    <script src="https://code.jquery.com/jquery-3.2.1.slim.min.js" integrity="sha384-KJ3o2DKtIkvYIK3UENzmM7KCkRr/rE9/Qpg6aAZGJwFDMVNA/GpGFF93hXpG5KkN" crossorigin="anonymous"></script>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.12.9/umd/popper.min.js" integrity="sha384-ApNbgh9B+Y1QKtv3Rn7W3mgPxhU9K/ScQsAP7hUibX39j7fakFPskvXusvfa0b4Q" crossorigin="anonymous"></script>
    <script src="js/bootstrap.min.js"></script>
  </body>
</html>