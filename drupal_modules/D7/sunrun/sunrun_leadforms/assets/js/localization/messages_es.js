/*
 * Translated default messages for the jQuery validation plugin.
 * Locale: ES (Spanish; Español)
 */
'use strict';
(function ($) {
  Drupal.behaviors.sunrun_jquery_validate_config_spanish = {
    attach: function (context, settings) {
      if ($.validator) {
        $.extend($.validator.messages, {
          required: 'Este campo es obligatorio.',
          remote: 'Por favor, rellena este campo.',
          email: 'Favor ingrese un correo electrónico válido.',
          url: 'Por favor, escribe una URL válida.',
          date: 'Por favor, escribe una fecha válida.',
          dateISO: 'Por favor, escribe una fecha (ISO) válida.',
          number: 'Por favor, escribe un número válido.',
          digits: 'Por favor, escribe sólo dígitos.',
          creditcard: 'Por favor, escribe un número de tarjeta válido.',
          equalTo: 'Por favor, escribe el mismo valor de nuevo.',
          extension: 'Por favor, escribe un valor con una extensión aceptada.',
          maxlength: $.validator.format('Por favor, no escribas más de {0} caracteres.'),
          minlength: $.validator.format('Por favor, no escribas menos de {0} caracteres.'),
          rangelength: $.validator.format('Por favor, escribe un valor entre {0} y {1} caracteres.'),
          range: $.validator.format('Por favor, escribe un valor entre {0} y {1}.'),
          max: $.validator.format('Por favor, escribe un valor menor o igual a {0}.'),
          min: $.validator.format('Por favor, escribe un valor mayor o igual a {0}.'),
          nifES: 'Por favor, escribe un NIF válido.',
          nieES: 'Por favor, escribe un NIE válido.',
          cifES: 'Por favor, escribe un CIF válido.',
          zipcode: 'Favor ingrese un código postal de cinco dígitos.',
          validname: "Favor ingrese un nombre valido.",
          phone: "Favor indique su número de teléfono.",
        });
      }
    }
  };
}(jQuery));