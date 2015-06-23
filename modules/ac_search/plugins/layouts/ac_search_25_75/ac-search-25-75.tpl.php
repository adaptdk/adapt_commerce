<?php
/**
 * @file
 * Template for a 2 column panel layout.
 *
 * This template provides a two column panel display layout, with
 * additional area for the top.
 *
 * Variables:
 * - $id: An optional CSS id to use for the layout.
 * - $content: An array of content, each item in the array is keyed to one
 *   panel of the layout. This layout supports the following sections:
 *   - $content['top']: Content in the top area.
 *   - $content['aside']: Content in the left column.
 *   - $content['middle']: Content in the right column.
 *
 */
?>
<section class="twocol-25-75">
  <div class="top">
    <?php if($content['top']): ?>
      <?php print $content['top']; ?>
    <?php endif;?>
  </div>
  <aside class="left-column aside">
    <?php if($content['aside']): ?>
      <?php print $content['aside']; ?>
    <?php endif;?>
  </aside>
  <section class="main middle">
    <?php if($content['middle']): ?>
      <?php print $content['middle']; ?>
    <?php endif;?>
  </section>
</section>
