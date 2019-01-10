<form action="<?php echo $form_action; ?>" method="POST" id="web-to-lead-form">

    <input type=hidden name="oid" value="<?php echo $oid; ?>">
    <input type=hidden name="retURL" value="<?php echo $base_url; ?>/ty/thank-you">

    <!--  ----------------------------------------------------------------------  -->
    <!--  NOTE: These fields are optional debugging elements. Please uncomment    -->
    <!--  these lines if you wish to test in debug mode.                          -->
    <!--  <input type="hidden" name="debug" value=1>                              -->
    <!--  <input type="hidden" name="debugEmail"                                  -->
    <!--  value="first.last@sunrunhome.com">                               -->
    <!--  ----------------------------------------------------------------------  -->
    <div class="form-group">
<!--        Zip code field temporarily pointed at notes field-->
        <label for="00N60000001aGx2">Código postal</label>
        <input class="form-control" id="00N60000001aGx2" maxlength="5" name="00N60000001aGx2" placeholder="99999" size="20" type="text" />
    </div>
    <div class="form-group">
        <label for="first_name">Nombre</label>
        <input class="form-control" id="first_name" maxlength="40" name="first_name" placeholder="Nombre" size="20" type="text" />
    </div>

    <div class="form-group">
        <label for="last_name">Apellido</label>
        <input class="form-control" id="last_name" maxlength="80" name="last_name" placeholder="Apellido" size="20" type="text" />
    </div>

    <div class="form-group">
        <label for="email">Correo electrónico</label>
        <input class="form-control" id="email" maxlength="80" name="email" placeholder="Correo electrónico" size="20" type="text" />

    </div>

    <div class="form-group">
        <label for="phone">Número de teléfono</label>
        <input class="form-control" id="phone" maxlength="40" name="phone" placeholder="(555) 555-5555" size="20" type="text" />
    </div>

    <div class="form-group">
    <label class="" for="00N32000002xUJh">Factura eléctrica mensual promedio</label>
    <select class="form-control" id="00N32000002xUJh" name="00N32000002xUJh">
        <option value="">-Seleccione la factura mensual promedio-</option>
        <option value="No Bill">Sin factura</option>
        <option value="$0-50">$0-50</option>
        <option value="$51-100">$51-100</option>
        <option value="$101-150">$101-150</option>
        <option value="$151-200">$151-200</option>
        <option value="$201-250">$201-250</option>
        <option value="$251-300">$251-300</option>
        <option value="$301-350">$301-350</option>
        <option value="$351-400">$351-400</option>
        <option value="$401+">$401+</option>
    </select>
    </div>
<!--  Channel-->
<input type="hidden" id="00N60000002YDag" name="00N60000002YDag" value="<?php echo $channel; ?>">
<!--    Lead Source-->
<input type="hidden" id="00N60000002YDal" name="00N60000002YDal" value="<?php echo $lead_source; ?>">
<!--    Lead Type-->
<input type="hidden" id="00N600000037ZLt" name="00N600000037ZLt" value="<?php echo $lead_type; ?>">

    <?php if (isset($primary_campaign_id) && isset($primary_campaign_value) ) : ?>
    <!-- Primary Campaign -->
    <input type="hidden" id="<?php echo $primary_campaign_id; ?>" name="<?php echo $primary_campaign_id; ?>" value="<?php echo $primary_campaign_value; ?>">
    <?php endif; ?>

    <?php if (isset($campaign_code_id) && isset($campaign_code_value) ) : ?>
    <!--    Campaign Code -->
<input type="hidden" id="<?php echo $campaign_code_id; ?>" name="<?php echo $campaign_code_id; ?>" value="<?php echo $campaign_code_value; ?>">
    <?php endif; ?>

    <div class="text-center ">
        <button type="submit" class="btn btn-cta">Solicite una cotización gratuita</button>
    </div>

    <div class="row" style="margin-top: 20px;">
        <div class="col-sm-12 text-left">
            <small class="pageid-tcpa">
                <?php echo $tcpa_spanish; ?>
            </small>
        </div>
    </div>

</form>
