<?php
global $user;
if ( $user->uid ) { ?>
    <div class="pdf_button submit">
        <span class="print_pdf"><a href="javascript:void(0);" title="Print this page." class="print-pdf export-btn" onclick="window.print(); return false" rel="nofollow">Print Preview</a></span>
    </div>
<?php } ?>
