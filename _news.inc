<?php require('../blog/wp-blog-header.php');?>

<?php 
    $args = array( 'numberposts' => 6, 'post_status'=>"publish",'post_type'=>"post",'orderby'=>"post_date");
    $postslist = get_posts( $args );
	function getImageUrl ($post)
	{
		$defaultUrl = "himg/blume.jpg";
    	$attch = wp_get_attachment_image_src(get_post_thumbnail_id($post->ID), array(64,64));
    	if ($attch == false) {
    		$attachments = get_posts( array('post_type' => 'attachment',
											'posts_per_page' => -1,
											'post_parent' => $post->ID));
    		$attch = wp_get_attachment_image_src($attachments[0]->ID, array(64,64));
    	}
    	if ($attch == false) {
    		return $defaultUrl; 
    	}
    	else {
			return $attch[0];
    	}
	}
	function new_excerpt_more($more) {
       global $post;
	return ' &hellip;'; //' <a href="'. get_permalink($post->ID) . '">Read the Rest...</a>';
	}
	add_filter('excerpt_more', 'new_excerpt_more');
?>
	<ul class="media-list">
 
<?php foreach ($postslist as $post) : setup_postdata($post); ?>
	
	<li class="media">
            <a class="pull-left" href="<?php the_permalink(); ?>">
                <img class="media-object size-64x64" width="64" height="64" src="<?php echo getImageUrl($post); ?>">
             </a>
            <div class="media-body">
				<h4 class="media-heading"><a href="<?php the_permalink(); ?>" title="<?php the_title(); ?>"><?php the_title(); ?></a> <small>vom <?php the_date(); ?></small></h4>
                
				<div class="news-content">
					<p><?php the_content(); ?> 
					<!--<a class="btn btn-small" 
							href="<?php the_permalink(); ?>" 
							title="<?php the_title(); ?>">Alles lesen &raquo;</a>/--><br /></p>
				<div>
            </div>
        </li>
<?php endforeach; ?> 
	</ul>